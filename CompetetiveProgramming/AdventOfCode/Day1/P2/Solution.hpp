#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


constexpr const char* test_file =
"C:"
"\\Users\\borah\\source\\repos\\CompetetiveProgramming\\CompetetiveProgramming\\AdventOfCode\\Day1\\P1\\TestInput."
"txt";

constexpr static const char* actual_test_file =
"C:\\Users\\borah\\source\\repos\\CompetetiveProgramming\\CompetetiveProgramming\\AdventOfCode\\Day1\\P1\\Input."
"txt";

static std::vector<int> depths;

static void init_depths_from_file(const char* t)
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
    for (const auto& d : depths)
    {
        std::cout << d << std::endl;
    }
}

/**
199  A
200  A B
208  A B C
210    B C D
200  E   C D
207  E F   D
240  E F G
269    F G H
260      G H
263        H

*/

size_t solution1(std::vector<int>& dps)
{
    uint32_t _ctr{};

    for (uint32_t idx{ 2 }; idx < dps.size() - 1; ++idx)
    {
        auto desired = dps[idx + (size_t)1];
        auto res = desired - dps[idx];
        if (res < 0)
            ++_ctr;
    }

    return dps.size() - _ctr - 1;
}


void solution()
{
    init_depths_from_file(test_file);
    for (int i = 0; i < depths.size()-2; ++i) 
    {
        depths[i] = depths[i] + depths[i + 1] + depths[i + 2];
    }

    depths.pop_back();
    depths.pop_back();

    display_depths();
    std::cout << solution1(depths) -1 << std::endl;
}