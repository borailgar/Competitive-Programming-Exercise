#pragma once

/**
 * Problem Title				: A. Computer Game
 * Time limit per test			: 2 seconds
 * memory limit per test		: 256 MB
 * input						: standart input
 * output						: standart output
 *
 * http://codeforces.com/problemset/problem/1598/A
 */

#include "../Utility/Matrix.h"
#include <stack>

#include <algorithm>
#include <functional>
#include <iostream>

struct Position
{
    Position(size_t _x, size_t _y) : x(_x), y(_y)
    {
    }

    size_t x, y;
};

struct Direction
{
    constexpr Direction(int16_t _x, int16_t _y) : x(_x), y(_y)
    {
    }

    int16_t x, y;
};

constexpr int ROW = 2;

#define REQUIRES(...) typename std::enable_if<(__VA_ARGS__), bool>::type = true
template <size_t COL, REQUIRES(COL >= 3)> using Grid_t = Matrix<int, COL, ROW>;
template <size_t COL, REQUIRES(COL >= 3)> using DiscoveryGrid_t = Matrix<bool, COL, ROW>;

constexpr int N = 8;
constexpr std::array<Direction, N> directions{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}};

template <size_t COL> bool depth_first_search(Grid_t<COL> &grid, const Position &pos)
{
    DiscoveryGrid_t<COL> discover_grid;
    discover_grid.fill(false);

    auto is_inside = [&](const Position &pos) -> bool {
        return (pos.x < grid.row_size()) && (pos.x >= 0) && (pos.y < grid.col_size()) && (pos.y >= 0);
    };

    auto is_equal = [](const Position &pos0, const Position &pos1) -> bool {
        return (pos0.x == pos1.x) && (pos0.y == pos1.y);
    };

    std::stack<Position> pos_stack;
    pos_stack.push(pos);

    while (!pos_stack.empty())
    {
        auto p = pos_stack.top();
        pos_stack.pop();

        if (!discover_grid[p.x][p.y])
        {
            discover_grid[p.x][p.y] = true;
            for (auto &dir : directions)
            {
                if (is_inside({p.x + dir.x, p.y + dir.y}) && grid[p.x + dir.x][p.y + dir.y] == 0)
                {
                    if (is_equal({p.x + dir.x, p.y + dir.y}, {1, COL - 1}))
                    {
                        std::cout << "YES\n";
                        return true;
                    }
                    pos_stack.emplace(p.x + dir.x, p.y + dir.y);
                }
            }
        }
    }
    std::cout << "NO\n";
    return false;
}

/**
int main()
{
    Grid_t<6> grid{{0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0}};
    Grid_t<4> grid_n{{0, 1, 1, 1, 1, 1, 1, 0}};

    depth_first_search(grid_n, {0, 0});

    return 0;
}

*/
