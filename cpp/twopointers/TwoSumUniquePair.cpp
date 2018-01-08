//
// Created by Guanqi Yu on 1/4/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
	/**
	 * note the difference here between partition
	 */
public:
	/*
	 * @param nums: an array of integer
	 * @param target: An integer
	 * @return: An integer
	 */
	int twoSum6(vector<int> &nums, int target) {
		if (nums.empty())   return 0;
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int count = 0;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum == target) {
				++left;
				--right;
				++count;
				while (left < right && nums[left] == nums[left - 1]) // no need boundary check because left is already ++ before
					++left;
				while (left < right && nums[right] == nums[right + 1])
					--right;
			} else if (sum > target)
				--right;
			else
				++left;
		}
		return count;
	}
};