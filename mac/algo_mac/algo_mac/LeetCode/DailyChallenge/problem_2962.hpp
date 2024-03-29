//
//  problem_2962.hpp
//  algo_mac
//
//  Created by zheka tolstikov on 29/03/2024.
//

#ifndef problem_2962_hpp
#define problem_2962_hpp

#include <stdio.h>
#include <vector>

using namespace std;

// 2962 Count subarrays where max element appears at least k times
// Sliding window technique

namespace Problem_2962
{
    class Solution
    {
    public:
        static long long countSubarrays(vector<int>& nums, int k)
        {
            long long res = 0;
            long long count = 0;
            long long left = 0;
            long long right = 0;
            int max = 0;
            
            for(int n : nums)
            {
                if(max < n)
                {
                    max = n;
                }
            }
            
            while(right < nums.size())
            {
                if(nums[right] == max)
                {
                    ++count;
                }
                
                while(count >= k)
                {
                    if(nums[left] == max)
                    {
                        --count;
                    }
                    
                    ++left;
                    res += nums.size() - right;
                }
                
                ++right;
            }
            
            return res;
        }
    };
}

#endif /* problem_2962_hpp */
