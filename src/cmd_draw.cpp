#include "tailcut.hpp"

namespace tailcut {

Result draw_command(const Options &options, const std::vector<Candidate> &items) {
    i64 total = 0;
    for (const Candidate &item : items) {
        total += item.weight;
        if (total > options.at) {
            return Result{0, item.token + "\n", ""};
        }
    }

    throw Failure{1, "draw position " + std::to_string(options.at) + " is outside the total " + std::to_string(total)};
}

} // namespace tailcut
