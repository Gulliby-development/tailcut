#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"check"}, "t0 1\nt1 1\nt2 1\nt3 1\nt4 1\nt5 1\nt6 1\nt7 1\nt8 1\nt9 1\nt10 1\nt11 1\nt12 1\nt13 1\nt14 1\nt15 1\nt16 1\nt17 1\nt18 1\nt19 1\nt20 1\nt21 1\nt22 1\nt23 1\nt24 1\nt25 1\nt26 1\nt27 1\nt28 1\nt29 1\nt30 1\nt31 1\n", 0, "ok, 32 candidates, total 32\n", ""},
    {{"check"}, "t0 1\nt1 1\nt2 1\nt3 1\nt4 1\nt5 1\nt6 1\nt7 1\nt8 1\nt9 1\nt10 1\nt11 1\nt12 1\nt13 1\nt14 1\nt15 1\nt16 1\nt17 1\nt18 1\nt19 1\nt20 1\nt21 1\nt22 1\nt23 1\nt24 1\nt25 1\nt26 1\nt27 1\nt28 1\nt29 1\nt30 1\nt31 1\nt32 1\n", 1, "", "tailcut: input is too long (max 32 lines)\n"},
    {{"check"}, "# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\n# c\na 1\n", 1, "", "tailcut: input is too long (max 32 lines)\n"},
    {{"check"}, "a 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\na 1\nb\n", 1, "", "tailcut: line 2: duplicate token a\n"},
    {{"share"}, "t0 1\nt1 1\nt2 1\nt3 1\nt4 1\nt5 1\nt6 1\nt7 1\nt8 1\nt9 1\nt10 1\nt11 1\nt12 1\nt13 1\nt14 1\nt15 1\nt16 1\nt17 1\nt18 1\nt19 1\nt20 1\nt21 1\nt22 1\nt23 1\nt24 1\nt25 1\nt26 1\nt27 1\nt28 1\nt29 1\nt30 1\nt31 1\n", 0, "t0 31\nt1 31\nt2 31\nt3 31\nt4 31\nt5 31\nt6 31\nt7 31\nt8 31\nt9 31\nt10 31\nt11 31\nt12 31\nt13 31\nt14 31\nt15 31\nt16 31\nt17 31\nt18 31\nt19 31\nt20 31\nt21 31\nt22 31\nt23 31\nt24 31\nt25 31\nt26 31\nt27 31\nt28 31\nt29 31\nt30 31\nt31 31\n", ""},
};

int main() {
    return check_rows(rows);
}
