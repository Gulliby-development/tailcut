#include "tailcut.hpp"

namespace tailcut {

Result share_command(const Options &options, const std::vector<Candidate> &items) {
    i64 total = 0;
    for (const Candidate &item : items) {
        total += item.weight;
    }

    i64 scale = 1000;
    if (options.unit == "percent") {
        scale = 100;
    } else if (options.unit == "ppm") {
        scale = 1000000;
    }

    std::vector<Row> rows;
    rows.reserve(items.size());
    for (const Candidate &item : items) {
        const i64 value = (item.weight * scale + total / 2) / total;
        rows.push_back(Row{item.token, value, scale});
    }
    return Result{0, render_rows(rows, options.format), ""};
}

} // namespace tailcut
