//
// Created by Guanqi Yu on 1/1/18.
//


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
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
			subset.push_back(nums[i]);
			dfs(nums, subset, results, i + 1);
			subset.pop_back();
		}
	}
};



class Solution2 {
	/**
	 * bit manipulation
	 */
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> results;
		for (int i = 0; i < (1 << nums.size()); ++i) {
			vector<int> subset;
			for (int j = 0; j < nums.size(); ++j) {
				if (i & (1 << j))
					subset.push_back(nums[j]);
			}
			results.push_back(subset);
		}
		return results;
	}
};