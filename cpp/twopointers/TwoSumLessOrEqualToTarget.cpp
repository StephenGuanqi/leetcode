//
// Created by Guanqi Yu on 1/4/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an array of integer
	 * @param target: an integer
	 * @return: an integer
	 */
	int twoSum5(vector<int> &nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int result = 0;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum <= target) {
				result += right - left;
				++left;
			} else
				--right;
		}
		return result;
	}
};

class Solution2 {
	/**
	 * Greater
	 */
public:
	/*
	 * @param nums: an array of integer
	 * @param target: An integer
	 * @return: an integer
	 */
	int twoSum2(vector<int> &nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int result = 0;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum > target) {
				result += right - left;
				--right;
			} else {
				++left;
			}
		}
		return result;
	}
};