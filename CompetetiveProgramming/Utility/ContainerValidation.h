#pragma once

/**
MIT License

Copyright(c) 2021 Bora Ilgar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <algorithm>
#include <array>
#include <ostream>
#include <random>
#include <string>

template <class Iter> void fill_with_random_int_values(Iter start, Iter end, int min, int max)
{
    static std::random_device rd;  // you only need to initialize it once
    static std::mt19937 mte(rd()); // this is a relative big object to create

    std::uniform_int_distribution<int> dist(min, max);

    std::generate(start, end, [&]() { return dist(mte); });
}

int str_compare(const char *s1, const char *s2)
{

    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

template <typename T, typename U, typename C = std::less<>> constexpr int compare(const T &v1, const U &v2, C cmp = C{})
{
    if (cmp(v1, v2))
    {
        return -1;
    }
    if (cmp(v2, v1))
    {
        return 1;
    }

    return 0;
}

template <size_t N> std::ostream &operator<<(std::ostream &os, const std::array<int, N> &arr)
{
    for (auto &i : arr)
    {
        os << i << ' ';
    }
    return os;
}

template <class FwdIt> std::ostream &display_container(std::ostream &os, FwdIt first, FwdIt last)
{
    for (; first != last; ++first)
    {
        os << *first << ' ';
    }
    return os;
}

// Check if provided container sorted
template <class BidirIt, class _Pred>
std::size_t sorted(BidirIt _First, BidirIt _Last, std::size_t &position, _Pred compare)
{
    bool is_sorted = true;

    BidirIt _MidIt = _First + (_Last - _First) / 2;
    if (compare(*_MidIt, *_First) || compare(*(_Last - 1), *_MidIt) || compare(*(_Last - 1), *_First))
        return !is_sorted;

    for (auto _FwdIt = _First; _FwdIt != _Last - 1 && is_sorted; _FwdIt++)
    {
        if (compare(*(_FwdIt + 1), *_FwdIt))
        {
            if (is_sorted == true)
                position = std::distance(_First, _FwdIt);

            is_sorted = false;
        }
    }

    return is_sorted;
}

// Find value block
template <typename FwdIt, typename Predicate>
auto find_if_block(FwdIt beg, FwdIt end, Predicate cmp)
    -> std::pair<typename FwdIt::difference_type, typename FwdIt::difference_type>
{
    typename FwdIt::difference_type start_index{};
    for (auto b = beg; b != end; ++b)
    {
        if (cmp(*b))
        {
            start_index = std::distance(beg, b);
            break;
        }
    }

    typename FwdIt::difference_type end_index{};
    std::for_each(beg + start_index, end, [&](typename FwdIt::value_type val) { cmp(val) ? end_index++ : end_index; });
    return std::make_pair(start_index, end_index);
}
