#include "tailcut.hpp"

#include <algorithm>
#include <numeric>

namespace tailcut {

std::vector<std::size_t> ranking(const std::vector<Candidate> &items) {
    std::vector<std::size_t> indexes(items.size());
    std::iota(indexes.begin(), indexes.end(), std::size_t{0});
    std::stable_sort(indexes.begin(), indexes.end(), [&items](std::size_t left, std::size_t right) {
        return items[left].weight > items[right].weight;
    });
    return indexes;
}

} // namespace tailcut
