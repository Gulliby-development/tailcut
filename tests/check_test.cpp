#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"check"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "ok, 5 candidates, total 1000\n", ""},
    {{"check"}, "a 1\n", 0, "ok, 1 candidate, total 1\n", ""},
    {{"check"}, "a 5\nb 0\n", 0, "ok, 2 candidates, total 5\n", ""},
    {{"check"}, "star 1584\nhill 242\nroad 1377\ndog 497\nsnow 4851\nsat 4500\nbig 3803\nice 3560\n", 0, "ok, 8 candidates, total 20414\n", ""},
    {{"check"}, "wind 276\nwave 3099\nsnow 4718\nice 2999\nmoon 1166\nbig 4343\nred 2294\nbear 0\ndog 3469\nlake 3496\nsat 1654\nroad 0\nhat 4339\na 1096\nran 1011\nfish 715\nthe 4911\nsky 1640\nhill 3517\nfire 0\n", 0, "ok, 20 candidates, total 44743\n", ""},
    {{"check"}, "bear 57762\na 160664\nhill 710179\nmoon 405903\nrain 259136\nred 162813\nroad 469130\nlake 503317\nbig 360936\nwind 879542\nhat 151013\nsat 789174\nsnow 860543\nfire 810482\ndog 415659\nice 269452\nran 403029\nmat 860218\nrock 208832\non 345305\ncat 689365\nthe 232460\nfrog 981863\nsand 508743\nsun 316804\nfish 684161\nbird 408787\ntree 310952\nwave 683225\nleaf 856220\nsky 249237\nstar 246187\n", 0, "ok, 32 candidates, total 15251093\n", ""},
};

int main() {
    return check_rows(rows);
}
