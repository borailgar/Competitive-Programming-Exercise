#pragma once

#include <vector>

/**
 * You are given an integer array height of length n. 
 * There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water. 
 * Return the maximum amount of water a container can store.
 * 
 */

class Solution 
{
public:
	int maxArea(std::vector<int>& height)
	{
		size_t begin{ 0 };
		size_t end{ height.size() - 1 };

		size_t max_area{};

		while (begin < end)
		{
			max_area = std::max(max_area, (end - begin) * std::min(height[begin], height[end]));
			if (height[begin] < height[end])
			{
				++begin;
			}
			else
			{
				--end;
			}

		}

		return max_area < 0 ? max_area *= -1 : max_area;
	}
};