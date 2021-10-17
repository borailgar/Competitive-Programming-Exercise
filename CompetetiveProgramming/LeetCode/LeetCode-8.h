#pragma once

#include "Utility/ContainerValidation.h"
#include <algorithm>
#include <map>
#include <string>
#include <type_traits>

bool is_negative = false;
int32_t result{};

int32_t myAtoi(std::string &s)
{
    const auto digitIterPair = find_if_block(s.begin(), s.end(), [](const char ch) { return ch >= '0' && ch <= '9'; });
    const auto check =
        std::count_if(s.begin(), s.begin() + digitIterPair.first, [](const char ch) { return ch >= 'a' && ch <= 'z'; });

    if (check > 0)
    {
        return 0;
    }

    const auto number = s.substr(digitIterPair.first, digitIterPair.second);

    if (digitIterPair.first >= 1 && s[digitIterPair.first - 1] == '-')
    {
        is_negative = true;
    }

    for (auto &idx : number)
    {
        int digit = idx - '0';
        if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7))
        {
            return is_negative ? INT_MIN : INT_MAX;
        }

        result = (result * 10) + digit;
    }
    return is_negative ? -result : result;
}
