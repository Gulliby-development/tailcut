#include "tailcut.hpp"

namespace tailcut {

namespace {

struct Step {
    std::string name;
    i64 value;
};

static i64 parse_value(const std::string &text) {
    i64 value = 0;
    for (char c : text) {
        value = value * 10 + (c - '0');
    }
    return value;
}

static std::vector<Step> split_steps(const std::string &steps) {
    std::vector<Step> result;
    std::size_t start = 0;
    while (start <= steps.size()) {
        std::size_t end = steps.find(',', start);
        if (end == std::string::npos) {
            end = steps.size();
        }
        const std::string text = steps.substr(start, end - start);
        const std::size_t colon = text.find(':');
        result.push_back(Step{text.substr(0, colon), parse_value(text.substr(colon + 1))});
        start = end + 1;
    }
    return result;
}

static Result run_step(const Step &step, const Options &options, const std::string &format,
                       const std::vector<Candidate> &items) {
    Options local = options;
    local.format = format;
    if (step.name == "topk") {
        local.k = step.value;
        return topk_command(local, items);
    }
    if (step.name == "topp") {
        local.p = step.value;
        return topp_command(local, items);
    }
    local.ratio = step.value;
    return minp_command(local, items);
}

} // namespace

Result chain_command(const Options &options, const std::vector<Candidate> &items) {
    const std::vector<Step> steps = split_steps(options.steps);
    std::vector<Candidate> survivors = items;
    for (std::size_t i = 0; i + 1 < steps.size(); i++) {
        const Result middle = run_step(steps[i], options, "plain", survivors);
        survivors = read_candidates(middle.out);
    }
    return run_step(steps.back(), options, options.format, survivors);
}

} // namespace tailcut
