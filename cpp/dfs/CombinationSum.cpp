//
// Created by Guanqi Yu on 1/1/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidate, int target) {
		// sort and eliminate duplicate
		sort(candidate.begin(), candidate.end());
		candidate.erase(unique(candidate.begin(), candidate.end()), candidate.end());
		// recursion DFS
		vector<vector<int>> results;
		vector<int> combination;
		dfs(candidate, 0, results, combination, 0, target);
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
			combination.push_back(nums[i]);
			// same as: sum += nums[i]
			dfs(nums, i, results, combination, sum + nums[i], target);
			// sum -= nums[i]
			combination.pop_back();
		}

	}
};



class Solution2 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> results;
		vector<int> combination;
		dfs(candidates, results, combination, 0, target);
		return results;
	}
private:
	void dfs(const vector<int> &candidates, vector<vector<int>> &results, vector<int> &combination,
	         int startIndex, int target) {
		if (!target) {
			results.push_back(combination);
			return;
		}
		for (int i = startIndex; target >= candidates[i] && i < candidates.size(); ++i) {
			combination.push_back(candidates[i]);
			dfs(candidates, results, combination, i, target - candidates[i]);
			combination.pop_back();
		}
	}
};

class Solution3 {
	/**
	 * output order length from small to largest
	 */
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> results;
		vector<int> combination;
		for (int n = 1; n <= target / candidates[0]; ++n)
			dfs(candidates, results, combination, 0, 0, n, target);
		return results;
	}
private:
	void dfs(const vector<int> &candidates, vector<vector<int>> &results, vector<int> &combination,
	         int startIndex, int startDepth, int endDepth, int target) {
		if (startDepth == endDepth && !target) {
			results.push_back(combination);
			return;
		}
		for (int i = startIndex; i < candidates.size(); ++i) {
			if (candidates[i] > target) break;
			combination.push_back(candidates[i]);
			dfs(candidates, results, combination, i, startDepth + 1, endDepth, target - candidates[i]);
			combination.pop_back();
		}
	}
};