#include "tailcut.hpp"

namespace tailcut {

std::string render_rows(const std::vector<Row> &rows, const std::string &format) {
    std::string output;
    for (const Row &row : rows) {
        output += row.token;
        output += format == "csv" ? ',' : ' ';
        output += std::to_string(row.value);
        if (format == "bar") {
            output += ' ';
            output += bar(row.value, row.full);
        }
        output += '\n';
    }
    return output;
}

std::string plural(std::size_t count, const std::string &noun) {
    return std::to_string(count) + " " + noun + (count == 1 ? "" : "s");
}

} // namespace tailcut
