#include <iostream>
#include "atview.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <cctype>

struct lower
{
    char operator()(char ch) const
    {
        return std::tolower(ch);
    }
};

struct calc
{
    int operator()(int i) const
    {
        return (i / 2) + 1;
    }
};

struct id
{
    double operator()(double x) const
    {
        return x;
    }
};

const int max = 1000;

bool check()
{
    double da[] = {7.43, 2.11, 6.49};
    int ia[max];
    for (int i = 0; i < max; ++i)
    {
        ia[i] = i * 2;
    }


    const char *msg = "Hello";
    const array_transform_view<char, lower> mv(msg, std::strlen(msg));

    array_transform_view<int, calc> iv(ia, max);

    array_transform_view<double, id> dv(da, sizeof(da) / sizeof(da[0]));

    da[1] = 1.54;
    ia[max / 2] = 2;

    if ('h' != mv.at(0) || 'l' != mv.at(2) || dv.at(2) <= 6.3 ||
        1.6 <= dv.at(1) || 1 != iv.at(0) || dv.at(0) <= 7.2 ||
        2 != iv.at(max / 2) || max != iv.at(max - 1))
    {
        return false;
    }

    if (5 != mv.size() || 'h' != mv[0] || 'o' != mv[4] ||
        3 != iv[2] || 'e' != mv[1] || max != iv.size())
    {
        return false;
    }

    std::vector<int> v;
    v.push_back(2);
    v.push_back(max);
    v.push_back(max / 2);
    v.push_back(max * 2);

    std::vector<double> a;
    a.push_back(4.32);

    array_transform_view<int, calc> vv(v);
    const array_transform_view<double, id> av(a);

    a[0] = 1.83;

    return (1 == av.size() && av[0] < 1.9 && 2 == vv[0] &&
            max / 2 + 1 == vv[1] && 1 + max == vv[3]);
}

int main()
{
    std::cout
            << "Your solution is " << (check() ? "" : "not ")
            << "ready for submission.\n";
}
