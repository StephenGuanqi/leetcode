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
	int maxProfit(int K, vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size();
		if (K > n / 2) {
			int sum = 0;
			for (int i = 1; i < n; ++i) {
				if (prices[i] > prices[i - 1])
					sum += prices[i] - prices[i - 1];
			}
			return sum;
		}

		vector<vector<int>> F(n + 1, vector<int>(2 * K + 2));
		// init
		fill_n(F[0].begin() + 1, 2 * K + 1, INT_MIN);
		F[0][1] = 0;

		for (int i = 1; i <= n; ++i) {
			// F[i][j] = max(F[i - 1][j], F[i - 1][j - 1] + A[i - 1] - A[i - 2])
			for (int j = 1; j <= 2 * K + 1; j += 2) {
				F[i][j] = F[i - 1][j];
				// j > 1 because F[i][1] only equals to F[i - 1][1]
				if (i >= 2 && j > 1 && F[i - 1][j - 1] != INT_MIN) {
					F[i][j] = max(F[i][j], F[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
				}
			}
			// F[i][j] = max(F[i - 1][j] + A[i - 1] - A[i - 2], F[i - 1][j - 1])
			for (int j = 2; j <= 2 * K; j += 2) {
				F[i][j] = F[i - 1][j - 1];
				if (i >= 2 && F[i - 1][j] != INT_MIN){
					F[i][j] = max(F[i][j], F[i - 1][j] + prices[i - 1] - prices[i - 2]);
				}
			}

		}

		// solution
		int res = 0;
		for (int i = 1; i <= 2 * K + 1; i += 2) {
			res = max(res, F[n][i]);
		}
		return res;
	}
};
