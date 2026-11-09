#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"chain", "--steps", "topk:3"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"chain", "--steps", "topk:3,topk:2"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"chain", "--steps", "topk:4,topp:900"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"chain", "--steps", "topp:900,topk:2"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"chain", "--steps", "minp:100,topp:950"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"chain", "--steps", "topp:990,minp:100"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"chain", "--steps", "topk:3,minp:500"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"chain", "--steps", "minp:500,topk:5"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"chain", "--steps", "topk:2,topp:1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"chain", "--steps", "topk:5,topp:800,minp:200,topk:1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"chain", "--steps", "topk:4,topp:600", "--format", "csv"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b,20\nc,20\ne,20\n", ""},
    {{"chain", "--steps", "topk:3,minp:600", "--format", "bar"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20 ####################\nc 20 ####################\ne 20 ####################\n", ""},
    {{"chain", "--steps", "topp:800,minp:150"}, "ran 3483\nbig 884\nlake 2776\ncat 1764\ndog 4099\nthe 144\nfrog 3446\nwind 2465\nrock 3956\nsat 4447\n", 0, "sat 4447\ndog 4099\nrock 3956\nran 3483\nfrog 3446\nlake 2776\n", ""},
    {{"chain", "--steps", "topk:8,topp:700,minp:100"}, "bird 3339\nred 2083\ndog 0\na 0\nrain 3261\nran 715\ncat 117\nsand 0\nhill 4608\nmat 39\ntree 2115\nroad 3561\nice 1400\nsat 3571\nbear 816\nmoon 2173\n", 0, "hill 4608\nsat 3571\nroad 3561\nbird 3339\nrain 3261\n", ""},
};

int main() {
    return check_rows(rows);
}
