#pragma once
#include <vector>
#include <iostream>

// 442. Find All Duplicates in an Array

namespace FindAllDuplicatesInArray
{
	class Solution
	{
	public:
		static std::vector<int> findDuplicates(std::vector<int>& nums)
		{
			int prev = 0;
			std::vector<int> res;
			for (size_t i = 0; i < nums.size(); ++i)
			{
				int index = abs(nums[i]);
				if (nums[index - 1] < 0)
				{
					res.push_back(index);
				}

				nums[index - 1] *= -1;
			}

			return res;
		}

		static void test()
		{
			std::vector<int> input = { 4,3,2,7,8,2,3,1 };
			std::vector<int> res = FindAllDuplicatesInArray::Solution::findDuplicates(input);

			for (int n : res)
			{
				std::cout << n << " ";
			}

			std::cout << std::endl;
		}
	};
}