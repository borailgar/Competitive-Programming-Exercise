#include <iostream>
#include <thread>
#include <map>
#include <stack>
#include <array>
#include <deque>
#include <condition_variable>
#include <mutex>
#include <vector>

int MaxAreaV2(const std::vector<int>& height)
{
	size_t begin{ 0 };
	size_t end{ height.size()-1};

	size_t max_area{};

	while (begin < end) 
	{
		auto m = (end - begin);
		auto _min = std::min(height[begin], height[end]);

		max_area = std::max(max_area, m * _min);
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



int main()
{
	std::vector<int> height{ 2,3,4,5,18,17,6 };
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	MaxAreaV2(height);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;



	return 0;
}