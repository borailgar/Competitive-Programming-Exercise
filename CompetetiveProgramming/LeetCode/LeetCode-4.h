#pragma once

#include "BinaryTree.h"

// Binary Tree
class Solution
{
  public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        BinTree bTree(nums1, nums2);
        bTree.to_vector();

        typedef std::vector<int>::size_type vec_sz;

        vec_sz size = bTree.list.size();
        if (size == 0)
            return 0;

        vec_sz mid = size / 2;

        return size % 2 == 0 ? (bTree.list[mid] + bTree.list[mid - 1]) / 2 : bTree.list[mid];
    }
};
