//
// Created by Guanqi Yu on 1/5/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an integer array
	 * @param target: An integer
	 * @return: the difference between the sum and the target
	 */
	int twoSumClosest(vector<int> &nums, int target) {
		if (nums.empty())   return 0;
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int minDiff = INT_MAX;
		while (left <  right) {
			int sum = nums[left] + nums[right];
			if (sum > target) {
				minDiff = min(minDiff, sum - target);
				--right;
			} else if (sum < target) {
				minDiff = min(minDiff, target - sum);
				++left;
			} else {
				return 0;
			}
		}
		return minDiff;
	}
};