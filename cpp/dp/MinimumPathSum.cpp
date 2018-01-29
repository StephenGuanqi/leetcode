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
	 * @param grid: a list of lists of integers
	 * @return: An integer, minimizes the sum of all numbers along its path
	 */
	int minPathSum(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> F(m, vector<int>(n));
		// init
		F[m - 1][n - 1] = grid[m - 1][n - 1];
		for (int i = n - 2; i >= 0; --i)
			F[m-1][i] = F[m-1][i + 1] + grid[m-1][i];
		for (int i = m - 2; i >= 0; --i)
			F[i][n - 1] = F[i + 1][n - 1] + grid[i][n - 1];

		for (int i = m - 2; i >= 0; --i)
			for (int j = n - 2; j>= 0; --j)
				F[i][j] = min(F[i][j + 1], F[i + 1][j]) + grid[i][j];

		return F[0][0];
	}
};