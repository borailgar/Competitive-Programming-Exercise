#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr const char *test_file =
    "C:"
    "\\Users\\borah\\source\\repos\\CompetetiveProgramming\\CompetetiveProgramming\\AdventOfCode\\Day1\\TestInput."
    "txt";

constexpr static const char *actual_test_file =
    "C:\\Users\\borah\\source\\repos\\CompetetiveProgramming\\CompetetiveProgramming\\AdventOfCode\\Day1\\Input."
    "txt";

static std::vector<int> depths;

static void init_depths_from_file(const char *t)
{
    depths.reserve(2000);
    std::ifstream infile(t);

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int depth;
        if (!(iss >> depth))
            break;
        depths.push_back(depth);
    }
}

static void display_depths()
{
    for (const auto &d : depths)
    {
        std::cout << d << std::endl;
    }
}

uint32_t solution()
{
    init_depths_from_file(actual_test_file);
    uint32_t _ctr{};

    for (uint32_t idx{2}; idx < depths.size() - 1; ++idx)
    {
        auto desired = depths[idx + (size_t)1];
        auto res = desired - depths[idx];
        if (res < 0)
            ++_ctr;
    }

    return depths.size() - _ctr - 1;
}
