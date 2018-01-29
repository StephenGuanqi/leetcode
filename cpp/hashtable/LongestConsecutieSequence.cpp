//
// Created by Guanqi Yu on 1/8/18.
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
	 * @param num: A list of integers
	 * @return: An integer
	 */
	int longestConsecutive(vector<int> &nums) {
		unordered_set<int> hash_set(nums.begin(), nums.end());
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (!hash_set.count(nums[i]))    continue;
			hash_set.erase(nums[i]);
			int pre = nums[i] - 1;
			while (hash_set.count(pre)) {
				hash_set.erase(pre);
				--pre;
			}
			int next = nums[i] + 1;
			while (hash_set.count(next)) {
				hash_set.erase(next);
				++next;
			}
			ans = max(ans, next - pre - 1);
		}
		return ans;
	}
};