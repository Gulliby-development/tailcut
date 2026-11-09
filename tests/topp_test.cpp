#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"topp", "--p", "1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"topp", "--p", "500"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"topp", "--p", "600"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"topp", "--p", "900"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"topp", "--p", "950"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"topp", "--p", "990"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\n", ""},
    {{"topp", "--p", "1000"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"topp", "--p", "500"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\n", ""},
    {{"topp", "--p", "1000"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\ne 20\na 10\nd 10\n", ""},
    {{"topp", "--p", "334"}, "a 1\nb 1\nc 1\n", 0, "a 1\nb 1\n", ""},
    {{"topp", "--p", "333"}, "a 1\nb 1\nc 1\n", 0, "a 1\n", ""},
    {{"topp", "--p", "700", "--format", "csv"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the,500\ncat,300\n", ""},
    {{"topp", "--p", "1"}, "a 0\nb 3\n", 0, "b 3\n", ""},

};

static const std::vector<Row> totals = {
    {{"topp", "--p", "800"}, "leaf 1917\nrock 3674\nice 3669\nroad 0\nstar 3548\na 2862\nlake 2246\nwave 805\nran 3502\nsat 2181\n", 0, "rock 3674\nice 3669\nstar 3548\nran 3502\na 2862\nlake 2246\nsat 2181\n", ""},
    {{"topp", "--p", "950"}, "road 2486\nmoon 0\nsky 3615\nred 2373\nthe 2074\nbird 0\nrain 2008\nwind 1745\nice 2918\nsun 591\nhat 2763\nsnow 3306\ndog 3385\nwave 2466\nmat 4597\na 766\n", 0, "mat 4597\nsky 3615\ndog 3385\nsnow 3306\nice 2918\nhat 2763\nroad 2486\nwave 2466\nred 2373\nthe 2074\nrain 2008\nwind 1745\n", ""},
    {{"topp", "--p", "500"}, "sun 1528\nbird 2599\nwave 4885\nhill 3611\ntree 3338\nthe 4543\nleaf 4663\nwind 3024\nred 1546\nhat 288\nsat 3871\nran 3516\nlake 1730\nsnow 2101\nrain 0\nstar 0\nsand 3384\nfish 561\nbig 3822\non 3384\nfire 4661\na 4760\nice 4745\nrock 4912\n", 0, "rock 4912\nwave 4885\na 4760\nice 4745\nleaf 4663\nfire 4661\nthe 4543\nsat 3871\n", ""},
    {{"topp", "--p", "900", "--format", "csv"}, "sand 97\nstar 3461\nice 923\nmoon 838\nbird 3812\nhill 1200\nsnow 3941\nlake 0\nhat 1112\ndog 4879\nsat 1557\nbig 1519\n", 0, "dog,4879\nsnow,3941\nbird,3812\nstar,3461\nsat,1557\nbig,1519\nhill,1200\nhat,1112\n", ""},
    {{"topp", "--p", "999"}, "tree 231146\nfrog 721041\ndog 367093\non 11870\nleaf 150897\nmat 966870\nroad 240372\nstar 0\nfish 747855\nran 929084\nbird 60378\nthe 436133\ncat 182108\nhill 583321\nbig 259951\nsand 691872\nice 855211\nfire 290083\nrain 472839\nbear 59730\nrock 330394\nwind 188602\nsun 925632\nsky 0\nhat 588785\na 143969\nred 133342\nsat 631993\nlake 274284\nsnow 272481\nwave 0\nmoon 780274\n", 0, "mat 966870\nran 929084\nsun 925632\nice 855211\nmoon 780274\nfish 747855\nfrog 721041\nsand 691872\nsat 631993\nhat 588785\nhill 583321\nrain 472839\nthe 436133\ndog 367093\nrock 330394\nfire 290083\nlake 274284\nsnow 272481\nbig 259951\nroad 240372\ntree 231146\nwind 188602\ncat 182108\nleaf 150897\na 143969\nred 133342\nbird 60378\nbear 59730\n", ""},
    {{"topp", "--p", "250", "--format", "bar"}, "snow 3929\nmat 4048\nbear 3503\na 1646\nran 341\nsky 2107\nbird 3057\nhill 3179\ntree 3567\non 2081\nsun 4043\nfrog 3699\nfire 834\nfish 1472\n", 0, "mat 4048 ####################\nsun 4043 ###################\nsnow 3929 ###################\n", ""},

};

int main() {
    return check_rows(rows) | check_rows(totals);
}
