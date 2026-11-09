#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"check"}, "", 1, "", ""},
    {{"share"}, "", 1, "", ""},
    {{"share", "--unit", "ppm"}, "", 1, "", ""},
    {{"share", "--format", "bar", "--unit", "percent"}, "", 1, "", ""},
    {{"topk", "--k", "3"}, "", 1, "", ""},
    {{"topp", "--p", "900"}, "", 1, "", ""},
    {{"minp", "--ratio", "0"}, "", 1, "", ""},
    {{"chain", "--steps", "topk:2,minp:100"}, "", 1, "", ""},
    {{"draw", "--at", "7"}, "", 1, "", ""},
    {{"share", "--format", "csv"}, "", 1, "", ""},
    {{}, "", 0, "", ""},
    {{"help"}, "", 0, "", ""},
    {{"-h"}, "", 0, "", ""},
    {{"--help"}, "", 0, "", ""},
    {{"--version"}, "", 0, "", ""},
    {{"frob"}, "", 0, "", ""},
    {{"check", "--format", "plain"}, "", 0, "", ""},
    {{"share", "--unit", "x"}, "", 0, "", ""},
    {{"topk"}, "", 0, "", ""},
    {{"topk", "--k", "0"}, "", 0, "", ""},
    {{"draw", "--at", "x"}, "", 0, "", ""},
    {{"chain", "--steps", "topk:2,"}, "", 0, "", ""},
    {{"Check"}, "", 0, "", ""},
};

int main() {
    return check_reads(rows);
}
