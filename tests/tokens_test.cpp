#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"check"}, "a 1\n", 0, "ok, 1 candidate, total 1\n", ""},
    {{"check"}, "abcdefghijkl 1\n", 0, "ok, 1 candidate, total 1\n", ""},
    {{"check"}, "abcdefghijklm 1\n", 1, "", "tailcut: line 1: bad token abcdefghijklm\n"},
    {{"check"}, "A.b_c-D9 1\n", 0, "ok, 1 candidate, total 1\n", ""},
    {{"check"}, "a:b 1\n", 1, "", "tailcut: line 1: bad token a:b\n"},
    {{"check"}, "a/b 1\n", 1, "", "tailcut: line 1: bad token a/b\n"},
    {{"check"}, "caf? 1\n", 1, "", "tailcut: line 1: bad token caf?\n"},
    {{"check"}, "a 0\n", 1, "", "tailcut: total weight is zero\n"},
    {{"check"}, "a 999999\n", 0, "ok, 1 candidate, total 999999\n", ""},
    {{"check"}, "a 1000000\n", 1, "", "tailcut: line 1: bad weight 1000000\n"},
    {{"check"}, "a 01\n", 1, "", "tailcut: line 1: bad weight 01\n"},
    {{"check"}, "a -1\n", 1, "", "tailcut: line 1: bad weight -1\n"},
    {{"check"}, "a +1\n", 1, "", "tailcut: line 1: bad weight +1\n"},
    {{"check"}, "a 1.5\n", 1, "", "tailcut: line 1: bad weight 1.5\n"},
    {{"check"}, "a 1e3\n", 1, "", "tailcut: line 1: bad weight 1e3\n"},
    {{"check"}, "a 1\na 2\n", 1, "", "tailcut: line 2: duplicate token a\n"},
    {{"check"}, "a 1\nA 2\n", 0, "ok, 2 candidates, total 3\n", ""},
    {{"check"}, "a 1\nb 2\na 3\n", 1, "", "tailcut: line 3: duplicate token a\n"},
    {{"check"}, "a x\n", 1, "", "tailcut: line 1: bad weight x\n"},
    {{"check"}, "a 0x10\n", 1, "", "tailcut: line 1: bad weight 0x10\n"},
};

int main() {
    return check_rows(rows);
}
