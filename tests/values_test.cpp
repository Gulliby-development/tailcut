#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"share", "--unit", "Permille"}, "", 2, "", "tailcut: bad value for --unit\n"},
    {{"share", "--unit", ""}, "", 2, "", "tailcut: bad value for --unit\n"},
    {{"share", "--format", "table"}, "", 2, "", "tailcut: bad value for --format\n"},
    {{"topk", "--k", "0"}, "", 2, "", "tailcut: bad value for --k\n"},
    {{"topk", "--k", "33"}, "", 2, "", "tailcut: bad value for --k\n"},
    {{"topk", "--k", "05"}, "", 2, "", "tailcut: bad value for --k\n"},
    {{"topk", "--k", "-1"}, "", 2, "", "tailcut: bad value for --k\n"},
    {{"topk", "--k", "2.5"}, "", 2, "", "tailcut: bad value for --k\n"},
    {{"topp", "--p", "0"}, "", 2, "", "tailcut: bad value for --p\n"},
    {{"topp", "--p", "1001"}, "", 2, "", "tailcut: bad value for --p\n"},
    {{"topp", "--p", "01"}, "", 2, "", "tailcut: bad value for --p\n"},
    {{"minp", "--ratio", "1001"}, "", 2, "", "tailcut: bad value for --ratio\n"},
    {{"minp", "--ratio", "-5"}, "", 2, "", "tailcut: bad value for --ratio\n"},
    {{"draw", "--at", "1000000000"}, "", 2, "", "tailcut: bad value for --at\n"},
    {{"draw", "--at", "007"}, "", 2, "", "tailcut: bad value for --at\n"},
    {{"draw", "--at", ""}, "", 2, "", "tailcut: bad value for --at\n"},
    {{"chain", "--steps", "topk"}, "", 2, "", "tailcut: bad value for --steps\n"},
    {{"chain", "--steps", "topk:0"}, "", 2, "", "tailcut: bad value for --steps\n"},
    {{"chain", "--steps", "topx:3"}, "", 2, "", "tailcut: bad value for --steps\n"},
    {{"chain", "--steps", "topk:3,"}, "", 2, "", "tailcut: bad value for --steps\n"},
    {{"chain", "--steps", "topk:1,topk:1,topk:1,topk:1,topk:1"}, "", 2, "", "tailcut: bad value for --steps\n"},
    {{"share", "--unit", "percent"}, "a 1\nb 2\n", 0, "a 33\nb 67\n", ""},
    {{"share", "--unit", "ppm"}, "a 1\nb 2\n", 0, "a 333333\nb 666667\n", ""},
    {{"topp", "--p", "1000"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"minp", "--ratio", "0"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"topk", "--k", "32"}, "a 1\nb 2\n", 0, "b 2\na 1\n", ""},
    {{"chain", "--steps", "topk:4,topp:900,minp:100,topk:1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
};

int main() {
    return check_rows(rows);
}
