#pragma once

#include <vector>

// Binary Tree
class Solution {
public:

	double calculate_median(const std::vector<int>& ivec)
	{
		auto _size = ivec.size();

		double median = _size % 2 == 0 ?
			(double(ivec[(_size / 2) - 1]) + double(ivec[(_size / 2)])) / 2 :
			ivec[(_size / 2)];

		return median;
	}

	template<typename FwdIt>
	std::vector<int> _merge(FwdIt beg0, FwdIt end0, FwdIt beg1, FwdIt end1)
	{
		std::vector<int> new_vec;

		while (beg0 != end0 && beg1 != end1)
		{
			if (*beg0 <= *beg1)
			{
				new_vec.push_back(*beg0);
				++beg0;
			}
			else
			{
				new_vec.push_back(*beg1);
				++beg1;
			}
		}

		for (auto b = beg0; b != end0; ++b) { new_vec.push_back(*b); }
		for (auto b = beg1; b != end1; ++b) { new_vec.push_back(*b); }

		return new_vec;
	}

	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		auto merged_vec = _merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
		return calculate_median(merged_vec);
	}
};