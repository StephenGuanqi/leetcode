//
// Created by Guanqi Yu on 1/5/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
	/**
	 * Same Direction pointers
	 */
public:
	/*
	 * @param nums: an integer array
	 * @return:
	 */
	void moveZeroes(vector<int>& nums) {
		// write your code here
		int left = 0; // first pos of zero
		int right = 0;
		while (right < nums.size()) {
			if (nums[right]) {
				swap(nums[right++], nums[left++]);
			} else {
				right++;
			}
		}
	}
};