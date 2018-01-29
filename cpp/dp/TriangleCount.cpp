//
// Created by Guanqi Yu on 1/26/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
	/*
	 * @param triangle: a list of lists of integers
	 * @return: An integer, minimum path sum
	 */
	int minimumTotal(vector<vector<int>> &triangle) {
		int m = triangle.size();
		int n = triangle[m - 1].size();
		vector<vector<int>> f(m, vector<int>(n));

		for (int j = 0; j < n; ++j)
			f[m - 1][j] = triangle[m - 1][j];

		for (int i = m - 2; i >= 0; --i) {
			for (int j = 0; j <= i; ++j)
				f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
		}

		return f[0][0];
	}
};