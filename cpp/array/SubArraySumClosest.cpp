//
// Created by Guanqi Yu on 1/8/18.
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
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> subarraySumClosest(vector<int> &nums) {
		vector<int> ans;
		if (nums.empty())   return ans;
		int len = nums.size();
		vector<pair<int, int>> prefixSum(len + 1); // {prefixSum, index}
		prefixSum[0] = {0, 0};
		for (int i = 1; i <= len; ++i) {
			prefixSum[i].first = prefixSum[i - 1].first + nums[i - 1];
			prefixSum[i].second = i;
		}
		sort(prefixSum.begin(), prefixSum.end(),
		     [] (pair<int, int> &p1, pair<int, int> &p2) { return p1.first < p2.first; });
		int minSum = INT_MAX;
		for (int i = 1; i <= len; ++i) {
			int diff = prefixSum[i].first - prefixSum[i - 1].first;
			if (diff <= minSum) {
				minSum = diff;
				ans.clear();
				// ans.push_back(prefixSum[i].second - 1);
				// ans.push_back(prefixSum[i-1].second);
				// sort(ans.begin(), ans.end());
				/**
				 * prefixSum larger index needs -1
				 * but before we know which sorted value has larger index, we
				 * can't directly minus
				 **/
				ans.push_back(prefixSum[i].second - 1);
				ans.push_back(prefixSum[i - 1].second - 1);
				sort(ans.begin(), ans.end());
				ans[0] += 1;
			}
		}
		return ans;
	}
};