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