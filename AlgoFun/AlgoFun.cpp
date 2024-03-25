// AlgoFun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LeetCode/BinarySearch/problem_234.h"

#include <iostream>
#include <math.h>       /* log10 */
#include <type_traits>
#include <algorithm>
#include <limits>

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp)
{
	// the machine epsilon has to be scaled to the magnitude of the values used
	// and multiplied by the desired precision in ULPs (units in the last place)
	return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
		// unless the result is subnormal
		|| std::fabs(x - y) < std::numeric_limits<T>::min();
}

int comparePowers(std::pair<long, long> n1, std::pair<long, long> n2) 
{
	if (n1.first == 1 && n2.first == 1)
	{
		return 0;
	}

	if (n1.first == n2.first)
	{
		if (n1.second == n2.second)
		{
			return 0;
		}

		return n1.second < n2.second ? 1 : -1;
	}

	if (n1.second == n2.second || n1.first == 1 || n2.first == 1)
	{
		return n1.first < n2.first ? 1 : -1;
	}

	double commonExponent = n1.second * log10(n1.first) / log10(n2.first);

	if (almost_equal((double)n2.second, commonExponent, 4))
	{
		return 0;
	}

	return n2.second < commonExponent ? -1 : 1;
}

int main()
{
	/*int res = comparePowers({ 1472213835, 7822137597 }, { 4044780372, 2191670062 });

    std::cout << "Res = " << res << std::endl;*/

	bool res = PalindromeLinkedList::Solution::test();

	std::cout << "Res = " << res << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
