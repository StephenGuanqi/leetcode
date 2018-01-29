//
// Created by Guanqi Yu on 1/25/18.
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
	 * @param nums: a rotated sorted array
	 * @return: the minimum number in the array
	 */
	int findMin(vector<int> nums) {
		int pivot = nums.back();
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] <= pivot)
				r = mid;
			else
				l = mid + 1;
		}
		return nums[l];
	}
};