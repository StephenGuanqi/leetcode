//
// Created by Guanqi Yu on 1/1/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		vector<int> subset;
		dfs(nums, subset, results, 0);
		return results;
	}
private:
	void dfs(const vector<int> &nums, vector<int> &subset,
	         vector<vector<int>> &results, int startIndex) {
		results.push_back(subset);
		for (int i = startIndex; i < nums.size(); ++i) {
			if (i > startIndex && nums[i] == nums[i - 1])   continue;
			subset.push_back(nums[i]);
			dfs(nums, subset, results, i + 1);
			subset.pop_back();
		}
	}
};