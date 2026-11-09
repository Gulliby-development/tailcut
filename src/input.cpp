#include "tailcut.hpp"

#include <unordered_set>

namespace tailcut {
namespace {

static bool is_space_or_tab(char value) {
    return value == ' ' || value == '\t';
}

static std::vector<std::string> words_of(const std::string &line) {
    std::vector<std::string> words;
    std::size_t pos = 0;
    while (pos < line.size()) {
        while (pos < line.size() && is_space_or_tab(line[pos])) {
            ++pos;
        }
        if (pos == line.size()) {
            break;
        }
        std::size_t end = pos;
        while (end < line.size() && !is_space_or_tab(line[end])) {
            ++end;
        }
        words.push_back(line.substr(pos, end - pos));
        pos = end;
    }
    return words;
}

static bool valid_token(const std::string &token) {
    if (token.empty() || token.size() > 12) {
        return false;
    }
    for (char value : token) {
        if (!((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z') ||
              (value >= '0' && value <= '9') || value == '_' || value == '.' ||
              value == '-')) {
            return false;
        }
    }
    return true;
}

static bool parse_weight(const std::string &word, i64 &weight) {
    if (word.empty() || word.size() > 6 || (word.size() > 1 && word[0] == '0')) {
        return false;
    }
    i64 value = 0;
    for (char digit : word) {
        if (digit < '0' || digit > '9') {
            return false;
        }
        value = value * 10 + (digit - '0');
    }
    weight = value;
    return true;
}

static std::size_t line_count(const std::string &input) {
    if (input.empty()) {
        return 0;
    }
    std::size_t count = 0;
    for (char value : input) {
        if (value == '\n') {
            ++count;
        }
    }
    if (input.back() != '\n') {
        ++count;
    }
    return count;
}

} // namespace

std::vector<Candidate> read_candidates(const std::string &input) {
    if (line_count(input) > MAX_LINES) {
        throw Failure{1, "input is too long (max 32 lines)"};
    }

    std::vector<Candidate> items;
    std::unordered_set<std::string> seen;
    i64 total = 0;
    std::size_t line_number = 0;
    std::size_t start = 0;
    while (start < input.size()) {
        const std::size_t newline = input.find('\n', start);
        const std::size_t end = newline == std::string::npos ? input.size() : newline;
        std::string line = input.substr(start, end - start);
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        ++line_number;

        const std::vector<std::string> words = words_of(line);
        if (!words.empty() && words[0][0] != '#') {
            if (words.size() != 2) {
                throw Failure{1, "line " + std::to_string(line_number) + ": expected TOKEN WEIGHT"};
            }
            if (!valid_token(words[0])) {
                throw Failure{1, "line " + std::to_string(line_number) + ": bad token " + words[0]};
            }
            i64 weight = 0;
            if (!parse_weight(words[1], weight)) {
                throw Failure{1, "line " + std::to_string(line_number) + ": bad weight " + words[1]};
            }
            if (seen.find(words[0]) != seen.end()) {
                throw Failure{1, "line " + std::to_string(line_number) + ": duplicate token " + words[0]};
            }
            seen.insert(words[0]);
            items.push_back(Candidate{words[0], weight});
            total += weight;
        }

        if (newline == std::string::npos) {
            break;
        }
        start = newline + 1;
    }

    if (items.empty()) {
        throw Failure{1, "no candidates"};
    }
    if (total == 0) {
        throw Failure{1, "total weight is zero"};
    }
    return items;
}

} // namespace tailcut
