#pragma once

#include "Matrix.h"
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

#define REQUIRES(...) typename std::enable_if<(__VA_ARGS__), bool>::type = true

struct Direction
{
    constexpr Direction(int _x, int _y) : x(_x), y(_y)
    {
    }
    int x, y;
};

template <typename T, size_t COL, size_t ROW, REQUIRES(COL >= 3 && ROW >= 3)> using Grid_t = Matrix<T, COL, ROW>;
template <size_t COL, size_t ROW, REQUIRES(COL >= 3 && ROW >= 3)> using DiscoveryGrid_t = Matrix<bool, COL, ROW>;

constexpr size_t N = 8;
constexpr std::array<Direction, N> directions{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}};

static uint32_t area_counter;

template <typename T, size_t M, size_t N> int breadth_first_search(Grid_t<T, M, N> &grid, const T &data)
{
    static_assert(M >= 3, "Column size must be bigger than 3");
    static_assert(N >= 3, "Row size must be bigger than 3");

    DiscoveryGrid_t<M, N> discovery_grid;
    discovery_grid.fill(false);

    discovery_grid[0][0] = true;

    using Position = Direction;

    std::queue<Position> ql;
    ql.emplace(0, 0);

    auto is_inside = [&](const Position &pos) -> bool {
        return (pos.x < grid.row_size()) && (pos.x >= 0) && (pos.y < grid.col_size()) && (pos.y >= 0);
    };

    while (!ql.empty())
    {
        auto p = ql.front();
        ql.pop();

        for (const auto &dir : directions)
        {
            if (is_inside({p.x + dir.x, p.y + dir.y}) && !discovery_grid[p.x + dir.x][p.y + dir.y] &&
                grid[p.x + dir.x][p.y + dir.y] == data)
            {
                discovery_grid[p.x + dir.x][p.y + dir.y] = true;
                ql.emplace(p.x + dir.x, p.y + dir.y);
                area_counter = ql.size();
            }
        }
    }

    return area_counter;
}
