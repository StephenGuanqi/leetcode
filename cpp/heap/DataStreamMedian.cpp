//
// Created by Guanqi Yu on 2/1/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: A list of integers
	 * @return: the median of numbers
	 */
	vector<int> medianII(vector<int> &nums) {
		vector<int> ans(nums.size());
		if (nums.empty())   return ans;
		ans[0] = nums[0];
		priority_queue<int> left; // max heap
		priority_queue<int, vector<int>, greater<int>> right; // min heap
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > ans[i - 1]) {
				right.push(nums[i]);
			} else {
				left.push(nums[i]);
			}
			if (left.size() == right.size() || left.size() + 1 == right.size())
				ans[i] = ans[i - 1];
			else if (left.size() == right.size() + 1) {
				right.push(ans[i - 1]);
				ans[i] = left.top();
				left.pop();
			} else {
				left.push(ans[i - 1]);
				ans[i] = right.top();
				right.pop();
			}
		}
		return ans;
	}
};