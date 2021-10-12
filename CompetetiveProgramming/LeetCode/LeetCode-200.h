
#include <array>
#include <iostream>
#include <queue>
#include <vector>

struct Direction
{
    constexpr Direction(int16_t _x, int16_t _y) : x(_x), y(_y)
    {
    }

    int16_t x, y;
};

template <size_t N, size_t M> using V_Arr = std::array<std::array<bool, N>, M>;

class Solution
{
  private:
    constexpr static uint32_t N = 4;
    constexpr static std::array<Direction, N> m_DirArray{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
    using Grid_t = std::vector<std::vector<char>>;
    using VisitGrid_t = std::vector<std::vector<bool>>;

  public:
    int32_t numIslands(Grid_t &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int32_t counter{};
        auto R = grid.size();
        auto C = grid.front().size();

        VisitGrid_t m_IsVisited(R, std::vector<bool>(C));

        for (size_t row{0}; row < R; ++row)
        {
            for (size_t col{0}; col < C; ++col)
            {
                if (!m_IsVisited[row][col] && grid[row][col] == '1')
                {
                    ++counter;
                    breadth_first_search(m_IsVisited, grid, row, col);
                }
            }
        }
        return counter;
    }

    void breadth_first_search(VisitGrid_t &is_visited, const Grid_t &grid, int32_t idxR, int32_t idxC)
    {
        std::queue<std::pair<int32_t, int32_t>> ql;
        ql.push({idxR, idxC});
        is_visited[idxR][idxC] = true;

        auto is_inside = [&](const size_t row, const size_t col) -> bool {
            return (row < grid.size()) && (row >= 0) && (col < grid[0].size()) && (col >= 0);
        };

        while (!ql.empty())
        {
            auto p = ql.front();
            ql.pop();

            for (const auto &dir : m_DirArray)
            {
                if (is_inside(p.first + dir.x, p.second + dir.y) && !is_visited[p.first + dir.x][p.second + dir.y] &&
                    grid[p.first + dir.x][p.second + dir.y] == '1')
                {
                    is_visited[p.first + dir.x][p.second + dir.y] = true;
                    ql.push({p.first + dir.x, p.second + dir.y});
                }
            }
        }
    }
};
