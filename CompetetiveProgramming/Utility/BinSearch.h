#pragma once

#include <algorithm>

// TODO: Given list must be sorted. So, implement a validation for it.
template <typename T, typename FwdIt> bool binary_search(FwdIt beg, FwdIt end, T &&data)
{
    auto length = std::distance(beg, end);
    if (length >= 1)
    {
        auto mid = beg + (length / 2);

        if (data == *mid)
        {
            return true;
        }

        if (*mid > data)
            return binary_search(beg, mid, data);

        else
            return binary_search(mid, end, data);
    }

    return false;
}
