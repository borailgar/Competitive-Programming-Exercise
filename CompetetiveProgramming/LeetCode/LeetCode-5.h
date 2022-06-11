#pragma once

#include <string>

/**
 * @brief Given a string s, return the longest palindromic substring in s.
 * @link https://leetcode.com/problems/longest-palindromic-substring/
*/

static int32_t expand_center(const std::string& s, int left, int right)
{
    int L = left;
    int R = right;

    while (L >= 0 && R < s.size() && s[L] == s[R])
    {
        L--;
        R++;
    }

    return R - L - 1;
}

static std::string longest_palindrome(std::string&& str)
{
    if (str.empty() || str.size() < 1 || str.size() > 1000)
        return "";

    if (str.size() == 1)
        return str;

    bool is_all_same = true;
    char ch = str[0];
    for (auto&& ss : str) { if (ch != ss) { is_all_same = false; } }

    if (is_all_same)
        return str;

    int32_t start{}, end{};
    for (int idx{}; idx < str.size(); ++idx)
    {
        int len1 = expand_center(str, idx, idx);
        int len2 = expand_center(str, idx, idx + 1);

        int len_max = std::max(len1, len2);

        if (len_max > end - start) {
            start = idx - (len_max - 1) / 2;
            end = idx + len_max / 2;
        }
    }
    return str.substr(start, end - start + 1);
}
