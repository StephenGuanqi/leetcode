//
// Created by Guanqi Yu on 1/5/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an array of Integer
	 * @param target: an integer
	 * @return: [index1 + 1, index2 + 1] (index1 < index2)
	 */
	vector<int> twoSum7(vector<int> &nums, int target) {
		vector<int> result;
		if (nums.empty())   return result;
		vector<pair<int, int>> pairs; // { {index, num[index]} ...  }
		// transform(nums.begin(), nums.end(), back_inserter(pairs),
		//           [](int num) -> pair<int, int> { return {}; })
		for (int i = 0; i < nums.size(); ++i)
			pairs.push_back({i, nums[i]});
		sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b) {
			return a.second < b.second;
		});
		if (target < 0) target = -target;
		int left = 0, right = 0;
		while (right < pairs.size()) {
			if (right == left)  ++right;
			int diff = pairs[right].second - pairs[left].second;
			if (diff < target) {
				++right;
			} else if (diff > target) {
				++left;
			} else {
				result.push_back(pairs[left].first + 1);
				result.push_back(pairs[right].first + 1);
				sort(result.begin(), result.end());
				return result;
			}
		}
		return result;
	}
};

class Solution2 {
public:
	/*
	 * @param nums: an array of Integer
	 * @param target: an integer
	 * @return: [index1 + 1, index2 + 1] (index1 < index2)
	 */
	vector<int> twoSum7(vector<int> &nums, int target) {
		vector<int> result;
		if (nums.empty())   return result;
		unordered_map<int, int> hashMap; // nums[index]--->index
		// target can be 5 or -5
		for (int i = 0; i < nums.size(); ++i) {
			int tmp = nums[i] - target;
			if (hashMap.count(tmp)) {
				result.push_back(hashMap[tmp] + 1);
				result.push_back(i + 1);
				return result;
			}
			tmp = nums[i] + target;
			if (hashMap.count(tmp)) {
				result.push_back(hashMap[tmp] + 1);
				result.push_back(i + 1);
				return result;
			}
			hashMap[nums[i]] = i;
		}
		return result;
	}
};