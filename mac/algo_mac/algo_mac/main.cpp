//
//  main.cpp
//  algo_mac
//
//  Created by zheka tolstikov on 29/03/2024.
//

#include "LeetCode/DailyChallenge/problem_2962.hpp"

#include <iostream>

int main(int argc, const char * argv[]) 
{
    
    vector<int> input = { 1,3,2,3,3 };
    int k = 2;
    
    Problem_2962::Solution::countSubarrays(input, k);
    
    std::cout << "Hello, World!\n";
    return 0;
}
