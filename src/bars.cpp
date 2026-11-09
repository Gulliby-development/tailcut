#include "tailcut.hpp"

namespace tailcut {

// The hash marks of a value against a full bar: twenty marks for the full value, rounded down, and at least one mark for any value above zero.
std::string bar(i64 value, i64 full) {
    if (value <= 0 || full <= 0) {
        return "";
    }
    i64 marks = value * 20 / full;
    if (marks < 1) {
        marks = 1;
    }
    if (marks > 20) {
        marks = 20;
    }
    return std::string(static_cast<std::size_t>(marks), '#');
}

} // namespace tailcut
