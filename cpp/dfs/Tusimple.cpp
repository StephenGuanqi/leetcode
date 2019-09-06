//
// Created by Guanqi Yu on 4/6/18.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> getPartitions(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int totalProduct = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
		int target = round(pow(totalProduct, 1.0 / 3));
		int n = nums.size();
		vector<vector<int>> combinations;
		vector<int> combination;
		vector<vector<int>> results;
		unordered_set<int> hashset(nums.begin(), nums.end());
		getCombination(nums, 0, combinations, combination, 1, target);
		if (combinations.size() == 1) {
			if (equal(combinations[0].begin(), combinations[0].end(), combinations[0].begin())) {
				results.assign(3, combinations[0]);
				return results;
			} else {
				return results;
			}
		}
		if (combinations.size() < 3)    return results;
		if (get3Subsets(0, combinations, results, hashset, target))
			return results;
		printf("yrdy");
		return vector<vector<int>>();
	}

private:
	// time complexity: O(n * 2 ^ n)
	// space complexity: recursion level: n, max size of recursion tree O(n * n) = O(n^2)
	// space is O(n^2)
//	bool getCombination(vector<int> &nums,
//	                    int startIndex,
//	                    vector<vector<int>> &results, vector<int> &combination,
//	                    vector<bool> &visited,
//	                    int product,
//	                    int visitedNum,
//	                    int target) {
//		if (product == target) {
//			results.push_back(combination);
//			product = 1;
//			combination.clear();
//			if (getCombination(nums, 0, results, combination, visited,
//			                   product, visitedNum, target))
//				return true;
//		}
//		// already visited all of elements
//		if (visitedNum == nums.size()) {
//			return results.size() == 3;
//		}
//		for (int i = startIndex; i < nums.size(); i++) {
//			if (product * nums[i] > target) break;
//			if (i > startIndex && nums[i - 1] == nums[i])   continue; // remove dup
//			if (visited[i]) continue;
//			combination.push_back(nums[i]);
//			visited[i] = true;
//			++visitedNum;
//			if (getCombination(nums, i + 1, results, combination, visited,
//			                   product * nums[i], visitedNum, target))
//				return true;
//			--visitedNum;
//			visited[i] = false;
//			combination.pop_back();
//		}
//		return false;
//	}
	bool get3Subsets(int startIndex, vector<vector<int>> &combinations, vector<vector<int>> &results,
					 unordered_set<int> &hashset, int target) {
		if (results.size() == 2) {
			int product = accumulate(hashset.begin(), hashset.end(), 1, multiplies<int>());
			if (product == target) {
				results.push_back(vector<int>(hashset.begin(), hashset.end()));
				return true;
			}
			return false;
		}
		for (int i = startIndex; i < combinations.size(); ++i) {
			bool flag = false;
			for (auto &num : combinations[i]) {
				if (!hashset.count(num)) { flag = true; break; }
				hashset.erase(num);
			}
			if (flag)   continue;
			results.push_back(combinations[i]);
			if (get3Subsets(i + 1, combinations, results, hashset, target))     return true;
			results.pop_back();
			for (auto &num : combinations[i]) {
				hashset.insert(num);
			}
		}
		return false;
	}

	void getCombination(vector<int> &nums,
	                    int startIndex,
	                    vector<vector<int>> &results, vector<int> &combination,
	                    int product,
	                    int target) {
		if (product == target) {
			results.push_back(combination);
			return;
		}

		for (int i = startIndex; i < nums.size(); i++) {
			if (product * nums[i] > target) break;
			if (i > startIndex && nums[i - 1] == nums[i])   continue; // remove dup
			combination.push_back(nums[i]);
			getCombination(nums, i + 1, results, combination,
			               product * nums[i], target);
			combination.pop_back();
		}
	}


};

//int main() {
//	vector<int> nums = {1, 1, 1, 1, 1};
//	auto res = Solution().getPartitions(nums);
//	for (auto partition : res) {
//		copy(partition.begin(), partition.end(), ostream_iterator<int>(cout, " "));
//		cout << endl;
//	}
//}