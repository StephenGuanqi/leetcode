//
// Created by Guanqi Yu on 3/16/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: A list of integer
	 * @return: An integer, maximum coins
	 */
	int maxCoins(vector<int> &nums) {
		// write your code here
		if (nums.empty())   return 0;

		// F[i][j] = F[i][k - 1] +n[i - 1] * n[k] * n [j + 1] + F[k + 1][j]
		// init  F[i][i] = n[i - 1] * n[i] * n[i + 1]

		int n = nums.size();
		vector<vector<int>> f(n, vector<int>(n, INT_MIN));

		// init
		for (int i = 0; i < n; ++i) {
			int prev = i - 1 < 0 ? 1 : nums[i - 1];
			int next = i + 1 >= n ? 1 : nums[i + 1];
			f[i][i] = prev * nums[i] * next;
		}

		// dp
		for (int len = 1; len < n; ++len) {
			for (int i = 0; i < n; ++i) {
				int j = i + len;
				if (j >= n)  break;
				int prev = i - 1 < 0 ? 1 : nums[i - 1];
				int next = j + 1 >= n ? 1 : nums[j + 1];
				for (int k = i; k <= j; ++k) {
					f[i][j] = max(f[i][j], (k - 1 < i ? 0 : f[i][k - 1] ) +
					                       (k + 1 > j ? 0 : f[k + 1][j]) +
					                       prev * nums[k] * next);
				}
			}
		}

		return f[0][n - 1];
	}

};