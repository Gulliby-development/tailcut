#include "harness.hpp"

static const std::vector<Row> rows = {
    {{}, "", 2, "", "usage: tailcut check\n       tailcut share [--unit UNIT] [--format FORMAT]\n       tailcut topk --k N [--format FORMAT]\n       tailcut topp --p PERMILLE [--format FORMAT]\n       tailcut minp --ratio PERMILLE [--format FORMAT]\n       tailcut chain --steps STEPS [--format FORMAT]\n       tailcut draw --at N\n"},
    {{"frob"}, "", 2, "", "tailcut: unknown command frob\n"},
};

int main() {
    return check_rows(rows);
}
