//
// Created by Guanqi Yu on 1/23/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an array of integers
	 * @param s: An integer
	 * @return: an integer representing the minimum size of subarray
	 */
	int minimumSize(vector<int> nums, int s) {
		int sz = nums.size();
		int sum = 0, j = 0;
		int ans = INT_MAX;
		for (int i = 0; i < sz; ++i) {
			while (j < sz && sum < s)
				sum += nums[j++];
			if (sum >= s)
				ans = min(ans, j - i);
			sum -= nums[i];
		}
		if (ans == INT_MAX)   return -1;
		return ans;
	}
};

