//
// Created by Guanqi Yu on 2/12/18.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an array with positive and negative numbers
	 * @param k: an integer
	 * @return: the maximum average
	 */
	double maxAverage(vector<int> &nums, int k) {
		if (nums.empty() || k > nums.size())   return 0;
		int min_val = *min_element(nums.begin(), nums.end());
		int max_val = *max_element(nums.begin(), nums.end());
		double start = min_val, end = max_val;
		double eps = 1e-5;
		while (end - start > eps) {
			double mid =  start + (end - start) / 2;
			if (checkValid(nums, mid, k)) {
				start = mid;
			} else {
				end = mid;
			}
		}
		return start;
	}

private:
	bool checkValid(vector<int> &nums, double mid, int k) {
		double pre_min = 0;
		vector<double> prefix_sum(nums.size() + 1);
		for (int i = 1; i <= nums.size(); ++i) {
			prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1] - mid;
			if (i >= k && prefix_sum[i] - pre_min >= 0)
				return true;
			if (i >= k)
				pre_min = min(pre_min, prefix_sum[i - k + 1]);
		}
		return false;
	}
};

