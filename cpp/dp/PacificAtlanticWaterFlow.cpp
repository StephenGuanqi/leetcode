//
// Created by Guanqi Yu on 3/27/18.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> res;
		if (matrix.empty() || matrix[0].empty())    return res;
		m = matrix.size();
		n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1)); // F[i][j] = 1 stands for pacific, 2 for atlantic, 3 for both
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] = calc(matrix, dp, i, j);
				if (dp[i][j] == 3)
					res.emplace_back(i, j);
			}
		}
		return res;
	}

private:
	int calc(vector<vector<int>>& matrix, vector<vector<int>> &dp, int x, int y) {
		if (dp[x][y] != -1)  return dp[x][y];
		if (x == m - 1 && y == 0 || x == 0 && y == n - 1)   return 3;
		if (x == 0 && y == 0)   return 1;
		if (x == m - 1 && y == n - 1)  return 2;
		int res = 0;
		for (int i = 0; i < 4; ++i) {
			int newx = x + diff[i][0];
			int newy = y + diff[i][1];
			if (newx < 0 || newy < 0 || newx >= m || newy >= n || matrix[newx][newy] > matrix[x][y])    continue;
			res |= calc(matrix, dp, newx, newy);
		}
		dp[x][y] = res;
		return dp[x][y];
	}

	int diff[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int m, n;
};

//int main() {
//	vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
//	auto res = Solution().pacificAtlantic(matrix);
//	for (auto p : res) {
//		cout << p.first << " " << p.second << endl;
//	}
//}