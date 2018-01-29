//
// Created by Guanqi Yu on 1/8/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
	/**
	 * intuitive way
	 */
public:
	/*
	 * @param nums: a list of integers.
	 * @param k: length of window.
	 * @return: the sum of the element inside the window at each moving.
	 */
	vector<int> winSum(vector<int> &nums, int k) {
		vector<int> ans;
		if (nums.empty() || k <= 0 || nums.size() < k) return ans;
		int ksum = accumulate(nums.begin(), nums.begin() + k, 0);
		for (int i = 0; i < nums.size() - k + 1; ++i) {
			ans.push_back(ksum);
			ksum -= nums[i];
			if (k + i < nums.size())
				ksum += nums[k + i];
		}
		return ans;
	}
};


class Solution2 {
	/**
	 * intuitive way
	 */
public:
	/*
	 * @param nums: a list of integers.
	 * @param k: length of window.
	 * @return: the sum of the element inside the window at each moving.
	 */
	vector<int> winSum(vector<int> &nums, int k) {
		vector<int> ans;
		if (nums.empty() || k <= 0 || nums.size() < k) return ans;
		int ksum = accumulate(nums.begin(), nums.begin() + k, 0);
		ans.push_back(ksum);
		for (int i = 1; i < nums.size() - k + 1; ++i) {
			ksum -= nums[i - 1];
			ksum += nums[i - 1 + k];
			ans.push_back(ksum);
		}
		return ans;
	}
};

