//
// Created by Guanqi Yu on 1/8/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
	/*
	 * @param nums: an array of integers
	 * @return: the number of unique integers
	 */
	int deduplication(vector<int> &nums) {
		// write your code here
		int n = nums.size(), m = 0;
		if (n == 0) return 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i) {
			if (nums[i] != nums[m]) {
				nums[++m] = nums[i];
			}
		}
		return m + 1;
	}
};