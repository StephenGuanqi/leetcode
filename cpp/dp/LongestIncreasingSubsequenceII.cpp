//
// Created by Guanqi Yu on 3/14/18.
//

#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param A: An integer matrix
	 * @return: an integer
	 */
	// flag not necessary here
	int longestIncreasingContinuousSubsequenceII(vector<vector<int>> &A) {
		if (A.empty() || A[0].empty())  return 0;
		int m = A.size(), n = A[0].size();

		vector<vector<int>> dp(m, vector<int>(n));
		flag = vector<vector<int>>(m, vector<int>(n));

		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] = search(i, j, A, dp);
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}

	int search(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp) {
		if (flag[x][y] != 0)
			return dp[x][y];
		// bool minimum = true;
		int ans = 1;
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < A.size() && yy >= 0 && yy < A[0].size()
			    && A[xx][yy] < A[x][y]) {
				// dp[x][y] = max(dp[x][y], search(xx, yy, A, dp) + 1);
				// minimum = false;
				ans = max(ans, search(xx, yy, A, dp) + 1);
			}
		}

		// if (!minimum)
		//     return dp[x][y];
		flag[x][y] = 1;
		dp[x][y] = ans;
		return ans;
	}

private:
	vector<int> dx = {0, 1, 0, -1};
	vector<int> dy = {1, 0, -1, 0};
	vector<vector<int>> flag;

};

//int main() {
//	vector<vector<int>> A = {{1, 3, 2}, {4, 6, 5}, {7, 9, 8}, {13, 15, 14}, {10, 12, 11}};
//	cout << Solution().longestIncreasingContinuousSubsequenceII(A) << endl;
//}