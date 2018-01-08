//
// Created by Guanqi Yu on 1/5/18.
//


#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> results;
		if (nums.empty())   return results;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			// remove dup
			if (i != 0 && nums[i] == nums[i - 1])    continue;
			for (int j = i + 1; j < nums.size(); ++j) {
				if (j != i + 1 && nums[j] == nums[j - 1])    continue;
				int start = j + 1;
				int end = nums.size() - 1;
				while (start < end) {
					int sum = nums[i] + nums[j] + nums[start] + nums[end];
					if (sum == target) {
						vector<int> result = {nums[i], nums[j], nums[start], nums[end]};
						results.push_back(result);
						++start;
						--end;
						while (start < end && nums[start] == nums[start - 1]) ++start;
						while (start < end && nums[end] == nums[end + 1])   --end;
					} else if (sum > target) {
						--end;
					} else {
						++start;
					}
				}
			}
		}
		return results;
	}
};