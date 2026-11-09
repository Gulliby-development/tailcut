#include "tailcut.hpp"

namespace tailcut {

Result check_command(const Options &, const std::vector<Candidate> &items) {
    i64 total = 0;
    for (const Candidate &item : items) {
        total += item.weight;
    }

    return Result{0, "ok, " + plural(items.size(), "candidate") + ", total " + std::to_string(total) + "\n", ""};
}

} // namespace tailcut
