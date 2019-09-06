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
	 * @param matrix: a matrix of 0 an 1
	 * @return: an integer
	 */
	int maxSquare2(vector<vector<int>> &matrix) {
		// write your code here
		if (matrix.empty() || matrix[0].empty())    return 0;
		int m = matrix.size(), n = matrix[0].size();

		vector<vector<int>> f(m, vector<int>(n));
		vector<vector<int>> up(m, vector<int>(n));   // how many zeros from the position up
		vector<vector<int>> left(m, vector<int>(n)); // how many zeros in the left position
		int res = 0;

		// dp
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					up[i][j] = (i == 0 || j == 0) ? 1 : up[i - 1][j] + 1;
					left[i][j] = (i == 0 || j == 0) ? 1 : left[i][j - 1] + 1;
					f[i][j] = 0;
				} else {
					up[i][j] = 0;
					left[i][j] = 0;
					if (i == 0 || j == 0)
						f[i][j] = 1;
					else
						f[i][j] = min(f[i - 1][j - 1],
						              min(up[i - 1][j], left[i][j - 1])) + 1;
				}
				res = max(res, f[i][j]);
			}
		}

		return res * res;
	}
};