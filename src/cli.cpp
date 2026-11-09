#include "tailcut.hpp"

#include <string>
#include <unordered_set>

namespace tailcut {
namespace {

static bool decimal_value(const std::string &text, i64 minimum, i64 maximum, i64 &value) {
    if (text.empty() || text.size() > std::to_string(maximum).size() ||
        (text.size() > 1 && text[0] == '0')) {
        return false;
    }
    i64 parsed = 0;
    for (char digit : text) {
        if (digit < '0' || digit > '9') {
            return false;
        }
        parsed = parsed * 10 + (digit - '0');
    }
    if (parsed < minimum || parsed > maximum) {
        return false;
    }
    value = parsed;
    return true;
}

static bool valid_steps(const std::string &steps) {
    std::size_t start = 0;
    std::size_t count = 0;
    while (start < steps.size()) {
        const std::size_t comma = steps.find(',', start);
        const std::size_t end = comma == std::string::npos ? steps.size() : comma;
        const std::string step = steps.substr(start, end - start);
        const std::size_t colon = step.find(':');
        if (colon == std::string::npos || step.find(':', colon + 1) != std::string::npos) {
            return false;
        }
        const std::string name = step.substr(0, colon);
        const std::string number = step.substr(colon + 1);
        i64 value = 0;
        if ((name == "topk" && decimal_value(number, 1, 32, value)) ||
            (name == "topp" && decimal_value(number, 1, 1000, value)) ||
            (name == "minp" && decimal_value(number, 0, 1000, value))) {
            ++count;
        } else {
            return false;
        }
        if (count > 4 || comma == std::string::npos) {
            if (count > 4) {
                return false;
            }
            return comma == std::string::npos;
        }
        start = comma + 1;
    }
    return false;
}

static const Command *find_command(const std::string &name) {
    for (const Command &command : COMMANDS) {
        if (name == command.name) {
            return &command;
        }
    }
    return nullptr;
}

static bool validate_arguments(const std::vector<std::string> &args, const Command *&command,
                               Options &options, std::string &error) {
    if (args.empty()) {
        error = USAGE;
        return false;
    }
    command = find_command(args[0]);
    if (command == nullptr) {
        error = "tailcut: unknown command " + args[0] + "\n";
        return false;
    }

    options = Options{"plain", "permille", -1, -1, -1, "", -1};
    std::unordered_set<std::string> supplied;
    for (std::size_t index = 1; index < args.size(); ++index) {
        const std::string &word = args[index];
        if (word.empty() || word == "-" || word[0] != '-') {
            error = "tailcut: unexpected argument " + word + "\n";
            return false;
        }
        bool known = word == "--format" || word == "--unit" || word == "--k" ||
                     word == "--p" || word == "--ratio" || word == "--steps" || word == "--at";
        if (!known) {
            error = "tailcut: unknown option " + word + "\n";
            return false;
        }
        bool allowed = false;
        for (const std::string &option : command->options) {
            if (option == word) {
                allowed = true;
                break;
            }
        }
        if (!allowed) {
            error = "tailcut: option " + word + " is not valid for " + command->name + "\n";
            return false;
        }
        if (supplied.find(word) != supplied.end()) {
            error = "tailcut: given twice: " + word + "\n";
            return false;
        }
        supplied.insert(word);
        if (index + 1 == args.size()) {
            error = "tailcut: missing value for " + word + "\n";
            return false;
        }
        const std::string &value = args[++index];
        i64 parsed = 0;
        bool valid = false;
        if (word == "--format") {
            valid = value == "plain" || value == "csv" || value == "bar";
            if (valid)
                options.format = value;
        } else if (word == "--unit") {
            valid = value == "permille" || value == "percent" || value == "ppm";
            if (valid)
                options.unit = value;
        } else if (word == "--k") {
            valid = decimal_value(value, 1, 32, parsed);
            if (valid)
                options.k = parsed;
        } else if (word == "--p") {
            valid = decimal_value(value, 1, 1000, parsed);
            if (valid)
                options.p = parsed;
        } else if (word == "--ratio") {
            valid = decimal_value(value, 0, 1000, parsed);
            if (valid)
                options.ratio = parsed;
        } else if (word == "--at") {
            valid = decimal_value(value, 0, 999999999, parsed);
            if (valid)
                options.at = parsed;
        } else {
            valid = valid_steps(value);
            if (valid)
                options.steps = value;
        }
        if (!valid) {
            error = "tailcut: bad value for " + word + "\n";
            return false;
        }
    }
    if (command->required[0] != '\0' && supplied.find(command->required) == supplied.end()) {
        error = "tailcut: missing " + std::string(command->required) + "\n";
        return false;
    }
    return true;
}

static bool is_help(const std::string &word) {
    return word == "help" || word == "-h" || word == "--help";
}

} // namespace

bool reads_stdin(const std::vector<std::string> &args) {
    if (args.empty() || is_help(args[0]) || args[0] == "--version") {
        return false;
    }
    const Command *command = nullptr;
    Options options;
    std::string error;
    return validate_arguments(args, command, options, error);
}

Result run(const std::vector<std::string> &args, const std::string &input) {
    if (!args.empty() && is_help(args[0])) {
        return Result{0, USAGE, ""};
    }
    if (!args.empty() && args[0] == "--version") {
        return Result{0, std::string(VERSION) + "\n", ""};
    }
    if (args.empty()) {
        return Result{2, "", USAGE};
    }

    const Command *command = nullptr;
    Options options;
    std::string error;
    try {
        if (!validate_arguments(args, command, options, error)) {
            return Result{2, "", error};
        }
        const std::vector<Candidate> items = read_candidates(input);
        return command->run(options, items);
    } catch (const Failure &failure) {
        return Result{failure.status, "", "tailcut: " + failure.message + "\n"};
    }
}

} // namespace tailcut
