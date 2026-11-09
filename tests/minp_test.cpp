#include "harness.hpp"

static const std::vector<Row> rows = {
    {{"minp", "--ratio", "0"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"minp", "--ratio", "1"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", ""},
    {{"minp", "--ratio", "50"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\nsat 40\n", ""},
    {{"minp", "--ratio", "100"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"minp", "--ratio", "300"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\ndog 150\n", ""},
    {{"minp", "--ratio", "301"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"minp", "--ratio", "600"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\ncat 300\n", ""},
    {{"minp", "--ratio", "1000"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the 500\n", ""},
    {{"minp", "--ratio", "500"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\ne 20\na 10\nd 10\n", ""},
    {{"minp", "--ratio", "1000"}, "a 10\nb 20\nc 20\nd 10\ne 20\n", 0, "b 20\nc 20\ne 20\n", ""},
    {{"minp", "--ratio", "100"}, "a 0\nb 5\n", 0, "b 5\n", ""},
    {{"minp", "--ratio", "250", "--format", "csv"}, "the 500\ncat 300\ndog 150\nsat 40\nmat 10\n", 0, "the,500\ncat,300\ndog,150\n", ""},

};

static const std::vector<Row> totals = {
    {{"minp", "--ratio", "100"}, "the 1469\nbig 3062\nlake 4607\nleaf 1757\ndog 362\nsnow 486\nstar 3499\nmat 1614\nfrog 0\nred 3404\n", 0, "lake 4607\nstar 3499\nred 3404\nbig 3062\nleaf 1757\nmat 1614\nthe 1469\nsnow 486\n", ""},
    {{"minp", "--ratio", "50"}, "mat 1269\nmoon 560\nhat 3369\nsnow 0\na 1471\nwave 1470\nsand 4983\nrock 56\nbig 2348\nroad 812\nsun 4665\nice 2821\nsky 4978\nstar 2514\nthe 596\ncat 0\nred 4057\ndog 2432\n", 0, "sand 4983\nsky 4978\nsun 4665\nred 4057\nhat 3369\nice 2821\nstar 2514\ndog 2432\nbig 2348\na 1471\nwave 1470\nmat 1269\nroad 812\nthe 596\nmoon 560\n", ""},
    {{"minp", "--ratio", "300"}, "ran 3885\nthe 525\nsky 0\nsnow 861\nhill 668\nbird 2308\ntree 1673\nhat 1548\nbig 1261\nleaf 714\nfire 1348\nstar 4502\nred 4406\nrain 2084\na 2857\nrock 4176\nice 0\ncat 213\nfrog 503\nwave 0\nlake 3671\nmoon 0\non 1111\nmat 4422\n", 0, "star 4502\nmat 4422\nred 4406\nrock 4176\nran 3885\nlake 3671\na 2857\nbird 2308\nrain 2084\ntree 1673\nhat 1548\n", ""},
    {{"minp", "--ratio", "200", "--format", "csv"}, "mat 2461\nrock 2271\nred 3069\ndog 2859\ncat 0\nmoon 154\nwind 1850\nsky 0\nfrog 1980\nsand 411\nhat 1361\non 3860\n", 0, "on,3860\nred,3069\ndog,2859\nmat,2461\nrock,2271\nfrog,1980\nwind,1850\nhat,1361\n", ""},
    {{"minp", "--ratio", "10"}, "lake 533732\nmoon 116310\nred 716520\nrock 674735\nstar 15044\nhat 0\nfish 556596\nfire 313870\nbig 207367\nsand 945678\nsky 940424\nrain 979858\nsun 31221\nroad 0\non 408559\nsat 493016\nwave 688260\nleaf 721373\nwind 734802\ncat 883851\na 605969\nbear 117317\nice 481337\ndog 196623\nsnow 310459\nbird 938732\nhill 288846\nmat 806591\nthe 580765\ntree 95883\nfrog 209985\nran 467591\n", 0, "rain 979858\nsand 945678\nsky 940424\nbird 938732\ncat 883851\nmat 806591\nwind 734802\nleaf 721373\nred 716520\nwave 688260\nrock 674735\na 605969\nthe 580765\nfish 556596\nlake 533732\nsat 493016\nice 481337\nran 467591\non 408559\nfire 313870\nsnow 310459\nhill 288846\nfrog 209985\nbig 207367\ndog 196623\nbear 117317\nmoon 116310\ntree 95883\nsun 31221\nstar 15044\n", ""},

};

int main() {
    return check_rows(rows) | check_rows(totals);
}
