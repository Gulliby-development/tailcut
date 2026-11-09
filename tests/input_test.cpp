#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"check"}, "", 1, "", "tailcut: no candidates\n"},
    {{"check"}, "\n", 1, "", "tailcut: no candidates\n"},
    {{"check"}, "# only\n\n   \n", 1, "", "tailcut: no candidates\n"},
    {{"check"}, "a 1", 0, "ok, 1 candidate, total 1\n", ""},
    {{"check"}, "a 1\nb 2", 0, "ok, 2 candidates, total 3\n", ""},
    {{"check"}, "a 1\r\nb 2\r\n", 0, "ok, 2 candidates, total 3\n", ""},
    {{"check"}, "a 1\nb 2 3\n", 1, "", "tailcut: line 2: expected TOKEN WEIGHT\n"},
    {{"check"}, "\n# c\na 1\nb\n", 1, "", "tailcut: line 4: expected TOKEN WEIGHT\n"},
    {{"check"}, "  a 1  \n\tb\t2\t\n", 0, "ok, 2 candidates, total 3\n", ""},
    {{"check"}, "a 1\n   # note\nb 2\n#c 3\n", 0, "ok, 2 candidates, total 3\n", ""},
    {{"check"}, "a 1\nfrob\nb 2\nx y\n", 1, "", "tailcut: line 2: expected TOKEN WEIGHT\n"},
    {{"check"}, "a 1\nb 2 #c\n", 1, "", "tailcut: line 2: expected TOKEN WEIGHT\n"},
    {{"check"}, "a 1\n\n\nb\n", 1, "", "tailcut: line 4: expected TOKEN WEIGHT\n"},
    {{"check"}, "a 0\nb 0\n", 1, "", "tailcut: total weight is zero\n"},
    {{"check"}, "a 0\nb 1\n", 0, "ok, 2 candidates, total 1\n", ""},
};

int main() {
    return check_rows(rows);
}
