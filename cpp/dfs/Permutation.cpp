//
// Created by Guanqi Yu on 1/2/18.
//
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> permutation;
		vector<bool> visited(nums.size());
		dfs(nums, results, visited, permutation);
		return results;
	}
private:
	void dfs(const vector<int> &nums, vector<vector<int>> &results,
	         vector<bool> &visited, vector<int> &permutation) {
		if (permutation.size() == nums.size()) {
			results.push_back(permutation);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i]) continue;
			permutation.push_back(nums[i]);
			visited[i] = true;
			dfs(nums, results, visited, permutation);
			visited[i] = false;
			permutation.pop_back();
		}
	}

};