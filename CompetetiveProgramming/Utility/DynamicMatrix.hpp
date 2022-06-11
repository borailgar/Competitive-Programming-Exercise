#pragma once
#include <iostream>

template <class T> struct DMatrix
{
    using value_type = T;
    using pointer_type = T *;
    using reference_type = T &;
    using const_pointer_type = const T *;
    using const_reference_type = const T &;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;

    DMatrix(size_type _h, size_type _w) : width(_w), height(_h)
    {
        matrix = new T *[_w];
        for (size_type i{0}; i < _w; ++i)
            matrix[i] = new T[_h];
    }

    const size_type size() const
    {
        return height * width;
    }

    const size_type height_size() const
    {
        return height;
    }

    const size_type width_size() const
    {
        return width;
    }

    [[noreturn]] const bool empty() const
    {
        return false;
    }

    T &at(size_type i, size_type j)
    {
        return matrix[i][j];
    }

    const T &at(size_type i, size_type j) const
    {
        return matrix[i][j];
    }

    ~DMatrix()
    {
        for (size_t i = 0; i < width; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

  private:
    T **matrix;
    size_type height;
    size_type width;
};
