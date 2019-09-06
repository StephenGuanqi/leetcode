//
// Created by Guanqi Yu on 2/22/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


class Solution {
public:
	/**
	 * @param costs: n x k cost matrix
	 * @return: an integer, the minimum cost to paint all houses
	 */
	int minCostII(vector<vector<int>> &costs) {
		if (costs.empty() || costs[0].empty())
			return 0;
		int n = costs.size(), k = costs[0].size();
		vector<vector<int>> f(n + 1, vector<int>(k));
		for (int i = 1; i <= n; ++i) {
			// get the min1 and min2 of f[i-1][:], O(K)
			int min1 = INT_MAX, min2 = INT_MAX;
			for (int j = 0; j < k; ++j) {
				if (f[i - 1][j] < min1) {
					min2 = min1;
					min1 = f[i - 1][j];
				} else {
					if (f[i - 1][j] < min2)
						min2 = f[i - 1][j];
				}
			}
			// dp
			for (int j = 0; j < k; ++j) {
				f[i][j] = (f[i - 1][j] == min1 ? min2 : min1) + costs[i - 1][j];
			}
		}
		// solution
		return *min_element(f[n].begin(), f[n].end());
	}
};