//
// Created by Guanqi Yu on 1/8/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: A list of integers
	 * @return: A integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int> &nums) {
		int minSum = 0;
		int ans = INT_MIN, sum = 0;
		for (auto num : nums) {
			sum += num;
			ans = max(ans, sum - minSum);
			minSum = min(minSum, sum);
		}
		return ans;
	}
};


class Solution2 {
	/**
	 * DP
	 */
public:
	/*
	 * @param nums: A list of integers
	 * @return: A integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int> &nums) {
		if (nums.empty())   return 0;
		int n = nums.size();
		vector<int> f(n + 1);
		f[1] = nums[0];
		for (int i = 2; i <= n; ++i) {
			f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
		}
		return *max_element(f.begin() + 1, f.end());
	}
};