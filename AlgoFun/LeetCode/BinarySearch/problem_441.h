#pragma once

// 441. Arranging Coins

namespace ArragingCoins
{
	class Solution
	{
	public:
		// Sum of first N natural numbers = n*(n+1)/2
		static int arrangeCoins(int n)
		{
			int low = 1;
			int high = n;
			while (low <= high) 
			{
				long long mid = low + (high - low) / 2;
				if (mid * (mid + 1) / 2 > n)
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			return high;
		}

		static int arrangeCoinsBasic(int n)
		{
			int res = 1;
			int k = 2;
			while ((n - k - 1) >= 0)
			{
				n -= k++;
				++res;
			}

			return res;
		}
	};
}