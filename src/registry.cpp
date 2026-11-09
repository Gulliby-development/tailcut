#include "tailcut.hpp"

namespace tailcut {

const char *const VERSION = "tailcut 0.1.0";
const std::size_t MAX_LINES = 32;

const char *const USAGE =
    "usage: tailcut check\n"
    "       tailcut share [--unit UNIT] [--format FORMAT]\n"
    "       tailcut topk --k N [--format FORMAT]\n"
    "       tailcut topp --p PERMILLE [--format FORMAT]\n"
    "       tailcut minp --ratio PERMILLE [--format FORMAT]\n"
    "       tailcut chain --steps STEPS [--format FORMAT]\n"
    "       tailcut draw --at N\n";

const std::vector<Command> COMMANDS = {
    {"check", {}, "", check_command},
    {"share", {"--unit", "--format"}, "", share_command},
    {"topk", {"--k", "--format"}, "--k", topk_command},
    {"topp", {"--p", "--format"}, "--p", topp_command},
    {"minp", {"--ratio", "--format"}, "--ratio", minp_command},
    {"chain", {"--steps", "--format"}, "--steps", chain_command},
    {"draw", {"--at"}, "--at", draw_command},
};

} // namespace tailcut
