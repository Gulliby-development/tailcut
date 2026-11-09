#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"share"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"share"}, "a 1\n", 0, "a 1000\n", ""},
    {{"share"}, "a 1\nb 1\n", 0, "a 500\nb 500\n", ""},
    {{"share"}, "a 1\nb 2\n", 0, "a 333\nb 667\n", ""},
    {{"share", "--unit", "percent"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 50\ncat 30\ndog 15\nsat 4\nmat 1\n", ""},
    {{"share", "--unit", "ppm"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500000\ncat 300000\ndog 150000\nsat 40000\nmat 10000\n", ""},
    {{"share"}, "a 1\nb 1\nc 1\n", 0, "a 333\nb 333\nc 333\n", ""},
    {{"share", "--unit", "percent"}, "a 1\nb 1\nc 1\n", 0, "a 33\nb 33\nc 33\n", ""},
    {{"share", "--format", "csv"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the,500\ncat,300\ndog,150\nsat,40\nmat,10\n", ""},
    {{"share", "--unit", "ppm", "--format", "csv"}, "a 2\nb 1\n", 0, "a,666667\nb,333333\n", ""},
    {{"share"}, "a 0\nb 5\n", 0, "a 0\nb 1000\n", ""},
    {{"share", "--unit", "percent"}, "x 3\ny 0\nz 7\n", 0, "x 30\ny 0\nz 70\n", ""},
    {{"share"}, "bird 2391\nhat 2789\nfish 2610\nmat 1464\nroad 2120\nsat 1917\n", 0, "bird 180\nhat 210\nfish 196\nmat 110\nroad 160\nsat 144\n", ""},
    {{"share", "--unit", "ppm"}, "cat 2511\na 2969\nmat 128\nstar 2380\nmoon 1937\nrock 2291\n", 0, "cat 205550\na 243042\nmat 10478\nstar 194826\nmoon 158563\nrock 187541\n", ""},
};

int main() {
    return check_rows(rows);
}
