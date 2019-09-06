//
// Created by Guanqi Yu on 2/14/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
	/*
	 * @param nums: An array of non-negative integers.
	 * @return: The maximum amount of money you can rob tonight
	 */
	int houseRobber2(vector<int> nums) {
		if (nums.empty())  return 0;
		if (nums.size() == 1)   return nums[0];
		int n = nums.size();
		vector<int> f(n);
		int res = 0;
		// f only stores max result end with ith number in the given range
		// total n - 1 number in total
		// nums[0] ~ nums[n - 2]
		f[0] = 0;
		f[1] = nums[0];
		for (int i = 2; i <= n - 1; ++i) {
			f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
		}
		res = f[n - 1];
		// nums[1] ~ nums[n - 1]
		f[0] = 0;
		f[1] = nums[1];
		for (int i = 2; i <= n - 1; ++i) {
			f[i] = max(f[i - 1], f[i - 2] + nums[i]);
		}
		res = max(res, f[n - 1]);
		return res;
	}

};