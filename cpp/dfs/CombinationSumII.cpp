//
// Created by Guanqi Yu on 1/1/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> results;
		vector<int> combination;
		dfs(candidates, 0, results, combination, 0, target);
		return results;
	}

private:
	// recursion definition: search all combinations set start with combinaiton and put into results
	void dfs(const vector<int> &nums,
	         int startIndex,
	         vector<vector<int>> &results, vector<int> &combination,
	         int sum,
	         int target) {
		// recursion out
		if (sum == target) {
			results.push_back(combination);
			return;
		}
		// recursion decompose
		for (int i = startIndex; i < nums.size(); i++) {
			if (sum + nums[i] > target) break;
			if (i > startIndex && nums[i - 1] == nums[i])   continue;
			combination.push_back(nums[i]);
			dfs(nums, i + 1, results, combination, sum + nums[i], target);
			combination.pop_back();
		}

	}

};