#include "tailcut.hpp"

#include <algorithm>

namespace tailcut {
namespace {

static std::vector<Row> make_rows(const std::vector<Candidate> &items,
                                  const std::vector<std::size_t> &indexes) {
    const i64 full = indexes.empty() ? 0 : items[indexes.front()].weight;
    std::vector<Row> rows;
    rows.reserve(indexes.size());
    for (std::size_t index : indexes) {
        rows.push_back(Row{items[index].token, items[index].weight, full});
    }
    return rows;
}

} // namespace

Result topk_command(const Options &options, const std::vector<Candidate> &items) {
    std::vector<std::size_t> indexes = ranking(items);
    if (indexes.size() > static_cast<std::size_t>(options.k)) {
        indexes.resize(static_cast<std::size_t>(options.k));
    }
    return Result{0, render_rows(make_rows(items, indexes), options.format), ""};
}

Result topp_command(const Options &options, const std::vector<Candidate> &items) {
    i64 total = 0;
    for (const Candidate &item : items) {
        total += item.weight;
    }

    const std::vector<std::size_t> ranked = ranking(items);
    std::vector<std::size_t> indexes;
    indexes.reserve(ranked.size());
    i64 cumulative = 0;
    for (std::size_t index : ranked) {
        indexes.push_back(index);
        cumulative += items[index].weight;
        if (cumulative * 1000 >= options.p * total) {
            break;
        }
    }
    return Result{0, render_rows(make_rows(items, indexes), options.format), ""};
}

Result minp_command(const Options &options, const std::vector<Candidate> &items) {
    const std::vector<std::size_t> ranked = ranking(items);
    const i64 maximum = items[ranked.front()].weight;
    std::vector<std::size_t> indexes;
    indexes.reserve(ranked.size());
    for (std::size_t index : ranked) {
        if (items[index].weight * 1000 >= options.ratio * maximum) {
            indexes.push_back(index);
        }
    }
    return Result{0, render_rows(make_rows(items, indexes), options.format), ""};
}

} // namespace tailcut
