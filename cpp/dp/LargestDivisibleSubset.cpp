//
// Created by Guanqi Yu on 1/29/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/*
	 * @param nums: a set of distinct positive integers
	 * @return: the largest subset
	 */
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		vector<int> ans;
		if (nums.empty())   return ans;
		// prev[i] ---> second last number index in the longest sequence ending with nums[i]
		vector<int> prev(nums.size());
		sort(nums.begin(), nums.end());
		auto f = vector<int>(nums.size(), 1);
		// dp
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && f[j] + 1 > f[i]) {
					f[i] = f[j] + 1;
					prev[i] = j;
				}
			}
		}
		// solution
		auto p = max_element(f.begin(), f.end());
		int pos = p - f.begin();
		ans.push_back(nums[pos]);
		while (pos != prev[pos]) {
			pos = prev[pos];
			ans.push_back(nums[pos]);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
