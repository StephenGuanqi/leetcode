//
// Created by Guanqi Yu on 1/28/18.
//
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: An integer array
	 * @return: The length of LIS (longest increasing subsequence)
	 */
	int longestIncreasingSubsequence(vector<int> &nums) {
		if (nums.empty())   return 0;
		// init
		auto F = vector<int>(nums.size(), 1);
		// dp
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j])
					F[i] = max(F[i], F[j] + 1);
			}
		}
		// solution
		return *max_element(F.begin(), F.end());
	}
};