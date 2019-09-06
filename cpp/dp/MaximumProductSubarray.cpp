//
// Created by Guanqi Yu on 2/14/18.
//


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	/**
	 * @param nums: An array of integers
	 * @return: An integer
	 */
	int maxProduct(vector<int> &nums) {
		if(nums.empty())    return 0;
		int n = nums.size();
		vector<long long> f(n + 1); // max product end with ith num
		vector<long long> g(n + 1); // min product end with ith num
		f[1] = nums[0];
		g[1] = nums[0];
		for (int i = 2; i <= n; ++i) {
			f[i] = max((long long)nums[i - 1], max(f[i - 1] * nums[i - 1],
			                                       g[i - 1] * nums[i - 1]));
			g[i] = min((long long)nums[i - 1], min(f[i - 1] * nums[i - 1],
			                                       g[i - 1] * nums[i - 1]));
		}
		return *max_element(f.begin() + 1, f.end());
	}
};