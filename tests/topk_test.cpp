#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"topk", "--k", "1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"topk", "--k", "2"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"topk", "--k", "3"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"topk", "--k", "5"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"topk", "--k", "6"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"topk", "--k", "32"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"topk", "--k", "2"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\n", ""},
    {{"topk", "--k", "3"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\ne 20\n", ""},
    {{"topk", "--k", "1"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\n", ""},
    {{"topk", "--k", "2", "--format", "csv"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the,500\ncat,300\n", ""},
    {{"topk", "--format", "csv", "--k", "4"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b,20\nc,20\ne,20\na,10\n", ""},
    {{"topk", "--k", "2"}, "a 0\nb 5\nc 0\n", 0, "b 5\na 0\n", ""},

};

static const std::vector<Row> totals = {
    {{"topk", "--k", "3"}, "moon 2633\nsat 3581\nwind 798\nrain 172\nbird 1211\nred 4193\ntree 4738\nbig 0\n", 0, "tree 4738\nred 4193\nsat 3581\n", ""},
    {{"topk", "--k", "5"}, "ran 2081\ntree 3034\nleaf 3998\nroad 2866\nfire 1514\ndog 3344\na 4681\ncat 3715\nsky 1775\nstar 0\nrock 502\nsat 1201\n", 0, "a 4681\nleaf 3998\ncat 3715\ndog 3344\ntree 3034\n", ""},
    {{"topk", "--k", "8"}, "wave 1659\nrock 744\nsun 2864\ncat 1068\nhat 1781\nstar 2220\nfire 401\nred 1941\nran 3522\nlake 0\nice 672\nsand 1566\nbear 1168\nmat 3991\nthe 4592\nfrog 2490\nhill 3360\na 3508\nsnow 484\nfish 736\n", 0, "the 4592\nmat 3991\nran 3522\na 3508\nhill 3360\nsun 2864\nfrog 2490\nstar 2220\n", ""},
    {{"topk", "--k", "4", "--format", "csv"}, "ice 3580\nrain 0\nstar 1308\nbird 1779\nmat 2733\ncat 0\nbear 0\nsand 865\ndog 4644\nmoon 3244\nwind 1399\nrock 3522\nthe 3110\nroad 1870\n", 0, "dog,4644\nice,3580\nrock,3522\nmoon,3244\n", ""},
    {{"topk", "--k", "10"}, "road 919856\nmoon 516663\nrain 176652\nfish 18776\nwave 646033\nsnow 73604\nthe 339620\na 94532\nmat 124979\nbear 380267\nbig 120015\non 488804\nfrog 592786\nice 900828\nhat 659552\nhill 4950\nran 998499\ndog 339751\nred 19684\nsat 814354\nsun 578816\ntree 10209\nlake 583881\nfire 196451\nleaf 854027\nrock 741708\nsand 128253\ncat 383130\nsky 539614\nstar 366202\nwind 405230\nbird 18859\n", 0, "ran 998499\nroad 919856\nice 900828\nleaf 854027\nsat 814354\nrock 741708\nhat 659552\nwave 646033\nfrog 592786\nlake 583881\n", ""},
    {{"topk", "--k", "2", "--format", "bar"}, "hill 2010\nlake 719\nfire 2442\nrain 863\nice 4207\nmat 163\nwind 4091\nsat 4908\nleaf 3337\n", 0, "sat 4908 ####################\nice 4207 #################\n", ""},

};

int main() {
    return check_rows(rows) | check_rows(totals);
}
