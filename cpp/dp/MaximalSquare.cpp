//
// Created by Guanqi Yu on 3/13/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
	/*
	 * @param matrix: a matrix of 0 and 1
	 * @return: an integer
	 */
	int maxSquare(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())    return 0;
		int m = matrix.size(), n = matrix[0].size();
		// integral matrix
		vector<vector<int>> sum(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]
				            + matrix[i - 1][j - 1];
			}
		}

		// traverse
		int res = 0;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				int maxe = min(m - i + 1, n - j + 1);
				for (int e = maxe; e >= 1; --e) {
					int area = sum[i + e - 1][j + e - 1] - sum[i + e - 1][j - 1]
					           - sum[i - 1][j + e - 1] + sum[i - 1][j - 1];
					if (area == e * e) {
						res = max(res, area);
					}
				}
			}
		}
		return res;

	}

	 int maxSquare2(vector<vector<int>>& matrix) {
	     if (matrix.empty() || matrix[0].empty())    return 0;
	     int m = matrix.size(), n = matrix[0].size();

	     vector<vector<int>> f(m, vector<int>(n));
	     int res = 0;
	     // init
	     for (int i = 0; i < m; ++i) {
	         f[i][0] = matrix[i][0] == 1 ? 1 : 0;
	         res = max(res, f[i][0]);
	     }
	     for (int j = 0; j < n; ++j) {
	         f[0][j] = matrix[0][j] == 1 ? 1 : 0;
	         res = max(res, f[0][j]);
	     }

	     // dp

	     for (int i = 1; i < m; ++i) {
	         for (int j = 1; j < n; ++j) {
	             if (matrix[i][j] == 0) {
	                 f[i][j] = 0;
	             } else {
		             f[i][j] = min(f[i - 1][j],
		                           min(f[i][j - 1], f[i - 1][j - 1])) + 1;
	                 res = max(f[i][j], res);
	             }
	         }
	     }

	     return res * res;
	 }

};