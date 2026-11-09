#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"help"}, "", 0, "usage: tailcut check\n       tailcut share [--unit UNIT] [--format FORMAT]\n       tailcut topk --k N [--format FORMAT]\n       tailcut topp --p PERMILLE [--format FORMAT]\n       tailcut minp --ratio PERMILLE [--format FORMAT]\n       tailcut chain --steps STEPS [--format FORMAT]\n       tailcut draw --at N\n", ""},
    {{"-h"}, "", 0, "usage: tailcut check\n       tailcut share [--unit UNIT] [--format FORMAT]\n       tailcut topk --k N [--format FORMAT]\n       tailcut topp --p PERMILLE [--format FORMAT]\n       tailcut minp --ratio PERMILLE [--format FORMAT]\n       tailcut chain --steps STEPS [--format FORMAT]\n       tailcut draw --at N\n", ""},
    {{"--help", "--bogus"}, "", 0, "usage: tailcut check\n       tailcut share [--unit UNIT] [--format FORMAT]\n       tailcut topk --k N [--format FORMAT]\n       tailcut topp --p PERMILLE [--format FORMAT]\n       tailcut minp --ratio PERMILLE [--format FORMAT]\n       tailcut chain --steps STEPS [--format FORMAT]\n       tailcut draw --at N\n", ""},
    {{}, "", 2, "", "usage: tailcut check\n       tailcut share [--unit UNIT] [--format FORMAT]\n       tailcut topk --k N [--format FORMAT]\n       tailcut topp --p PERMILLE [--format FORMAT]\n       tailcut minp --ratio PERMILLE [--format FORMAT]\n       tailcut chain --steps STEPS [--format FORMAT]\n       tailcut draw --at N\n"},
    {{"--version"}, "", 0, "tailcut 0.1.0\n", ""},
    {{"--version", "x"}, "", 0, "tailcut 0.1.0\n", ""},
    {{"frob"}, "", 2, "", "tailcut: unknown command frob\n"},
    {{""}, "", 2, "", "tailcut: unknown command \n"},
    {{"Check"}, "", 2, "", "tailcut: unknown command Check\n"},
    {{"-H"}, "", 2, "", "tailcut: unknown command -H\n"},
};

int main() {
    return check_rows(rows);
}
