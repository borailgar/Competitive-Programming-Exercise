#pragma once

#include <type_traits>

#define REQUIRES(x) typename = typename std::enable_if_t<std::is_integral_v<typename x>>

template <typename FwdIt, REQUIRES(FwdIt::value_type)>
auto find_non_repeatable(FwdIt beg, FwdIt end) -> typename FwdIt::value_type
{
    int32_t x = 0;
    for (auto b = beg; b != end; ++b)
    {
        x ^= *b;
    }
    return x;
}
