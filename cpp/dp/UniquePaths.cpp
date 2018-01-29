//
// Created by Guanqi Yu on 1/26/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	/*
	 * @param m: positive integer (1 <= m <= 100)
	 * @param n: positive integer (1 <= n <= 100)
	 * @return: An integer
	 */
	int uniquePaths(int m, int n) {
		vector<vector<int>> F(m, vector<int>(n));
		fill(F[m-1].begin(), F[m-1].end(), 1);
		for (int i = 0; i < m; ++i)
			F[i][n-1] = 1;
		for (int i = m - 2; i >= 0; --i)
			for (int j = n - 2; j >= 0; --j)
				F[i][j] = F[i + 1][j] + F[i][j + 1];
		return F[0][0];
	}
};