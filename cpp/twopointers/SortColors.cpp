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
	 * @param nums: A list of integer which is 0, 1 or 2
	 * @return: nothing
	 */
	void sortColors(vector<int> &nums) {
		// write your code here
		if (nums.empty())   return;
		// pl first pos is 1
		// pr first pos is 2
		int pl = 0, pr = nums.size() - 1;
		int i = 0;
		while ( i <= pr) {
			if (nums[i] == 2) {
				/**
				 * don't change i, we don't know what is nums[pr]
				 */
				swap(nums[pr], nums[i]);
				--pr;
			} else if (nums[i] == 0) {
				swap(nums[i], nums[pl]);
				++pl;
				++i;
			} else {
				++i;
			}
		}
	}
};