//
// Created by Guanqi Yu on 1/24/18.
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: An integer array sorted in ascending order
	 * @param target: An integer
	 * @return: An integer
	 */
	int lastPosition(vector<int> nums, int target) {
		if (nums.empty())   return -1;
		int left = 0, right = nums.size() -1;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				left = mid;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		if (nums[right] == target)
			return right;
		if (nums[left] == target)
			return left;
		return -1;
	}
};