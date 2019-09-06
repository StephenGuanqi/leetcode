//
// Created by Guanqi Yu on 2/22/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * @param prices: Given an integer array
	 * @return: Maximum profit
	 */
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) return 0;
		int n = prices.size();
		vector<vector<int>> F(n + 1, vector<int>(5 + 1));

		// init
		fill_n(F[0].begin() + 1, 5, INT_MIN);
		F[0][1] = 0;

		for (int i = 1; i <= n; ++i) {
			// F[i][j] = max(F[i - 1][j], F[i - 1][j - 1] + A[i - 1] - A[i - 2])
			for (int j = 1; j <= 5; j += 2) {
				F[i][j] = F[i - 1][j];
				// j > 1 because F[i][1] only equals to F[i - 1][1]
				if (i >= 2 && j > 1 && F[i - 1][j - 1] != INT_MIN) {
					F[i][j] = max(F[i][j], F[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
				}
			}
			// F[i][j] = max(F[i - 1][j] + A[i - 1] - A[i - 2], F[i - 1][j - 1])
			for (int j = 2; j < 5; j += 2) {
				F[i][j] = F[i - 1][j - 1];
				if (i >= 2 && F[i - 1][j] != INT_MIN){
					F[i][j] = max(F[i][j], F[i - 1][j] + prices[i - 1] - prices[i - 2]);
				}
			}

		}

		return max(F[n][1], max(F[n][3], F[n][5]));
	}
};