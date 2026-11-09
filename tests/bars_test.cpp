#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"share", "--format", "bar"}, "a 1\n", 0, "a 1000 ####################\n", ""},
    {{"share", "--format", "bar"}, "a 1\nb 1\n", 0, "a 500 ##########\nb 500 ##########\n", ""},
    {{"share", "--format", "bar"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500 ##########\ncat 300 ######\ndog 150 ###\nsat 40 #\nmat 10 #\n", ""},
    {{"share", "--unit", "percent", "--format", "bar"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 50 ##########\ncat 30 ######\ndog 15 ###\nsat 4 #\nmat 1 #\n", ""},
    {{"share", "--unit", "ppm", "--format", "bar"}, "a 1\nb 999999\n", 0, "a 1 #\nb 999999 ###################\n", ""},
    {{"share", "--format", "bar"}, "a 0\nb 5\n", 0, "a 0 \nb 1000 ####################\n", ""},
    {{"share", "--format", "bar"}, "a 19\nb 981\n", 0, "a 19 #\nb 981 ###################\n", ""},
    {{"share", "--format", "bar"}, "a 20\nb 980\n", 0, "a 20 #\nb 980 ###################\n", ""},
    {{"share", "--format", "bar"}, "a 49\nb 951\n", 0, "a 49 #\nb 951 ###################\n", ""},
    {{"share", "--format", "bar"}, "a 50\nb 950\n", 0, "a 50 #\nb 950 ###################\n", ""},
};

static const std::vector<Row> totals = {
    {{"share", "--format", "bar"}, "ice 0\nthe 1735\nrock 2692\nwind 2190\nbird 3108\nbear 630\nfrog 3428\nstar 0\non 4384\n", 0, "ice 0 \nthe 96 #\nrock 148 ##\nwind 121 ##\nbird 171 ###\nbear 35 #\nfrog 189 ###\nstar 0 \non 241 ####\n", ""},
    {{"share", "--unit", "percent", "--format", "bar"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 50 ##########\ncat 30 ######\ndog 15 ###\nsat 4 #\nmat 1 #\n", ""},
    {{"share", "--unit", "ppm", "--format", "bar"}, "mat 4307\ntree 3376\nice 562\nred 754\nsky 3093\nthe 4178\n", 0, "mat 264720 #####\ntree 207498 ####\nice 34542 #\nred 46343 #\nsky 190104 ###\nthe 256792 #####\n", ""},
    {{"share", "--format", "bar"}, "a 1\nb 2\nc 3\nd 4\ne 5\nf 100\n", 0, "a 9 #\nb 17 #\nc 26 #\nd 35 #\ne 43 #\nf 870 #################\n", ""},
    {{"share", "--format", "bar"}, "a 7\nb 7\nc 7\nd 7\n", 0, "a 250 #####\nb 250 #####\nc 250 #####\nd 250 #####\n", ""},
    {{"share", "--unit", "percent", "--format", "bar"}, "ran 38\nhill 27\nsun 37\nstar 40\nmat 24\nhat 14\non 40\nwind 17\nrock 14\nrain 34\nthe 30\nbig 34\n", 0, "ran 11 ##\nhill 8 #\nsun 11 ##\nstar 11 ##\nmat 7 #\nhat 4 #\non 11 ##\nwind 5 #\nrock 4 #\nrain 10 ##\nthe 9 #\nbig 10 ##\n", ""},
};

int main() {
    return check_rows(rows) | check_rows(totals);
}
