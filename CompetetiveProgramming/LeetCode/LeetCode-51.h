#pragma once

#include "../Utility/Matrix.h"


template<size_t N>
void PrintMaze(const Matrix<char, N, N>& maze)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

template<size_t N>
bool IsSafe(const Matrix<char, N, N>& maze, size_t row, size_t col)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < row; i++)
    {
        if (maze[i][col] == 'Q')
        {
            return false;
        }
    }

    // return 0 if two queens share the same `` diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (maze[i][j] == 'Q') {
            return false;
        }
    }

    // return 0 if two queens share the same `/` diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (maze[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

template<size_t N>
void N_Queen(Matrix<char, N, N>& maze, uint32_t row)
{
    if (row == N)
    {
        PrintMaze(maze);
        return;
    }

    for (size_t i = 0; i < N; ++i)
    {
        if (IsSafe(maze, row, i))
        {
            maze[row][i] = 'Q';

            N_Queen(maze, row + 1);

            maze[row][i] = '.';
        }
    }
}


/// TEST
/// constexpr size_t N = 5;
/// Matrix<char, N, N> maze;
/// maze.fill('.');
/// N_Queen(maze, 0);
///
///