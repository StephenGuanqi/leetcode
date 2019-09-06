//
// Created by Guanqi Yu on 3/12/18.
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
	 * @param values: a vector of integers
	 * @return: a boolean which equals to true if the first player will win
	 */
	bool firstWillWin(vector<int> &values) {
		// F[i][j] current take win how much
		// left = A[i] + min(F[i + 2][j], F[i + 1][j - 1])
		// right = A[j] + min(F[i][j - 2], F[i + 1][j - 1])
		// F[i][j] = max(left, right)
		if (values.empty()) return false;
		int n = values.size();
		F = vector<vector<int>>(n, vector<int>(n, INT_MIN));
		int sum = accumulate(values.begin(), values.end(), 0);
		return getDP(values, 0, n - 1) > sum / 2;
	}

	int getDP(vector<int> &values, int i, int j) {
		if (i == j)     return values[i];
		if (i + 1 == j)     return max(values[i], values[j]);
		if (F[i][j] != INT_MIN)     return F[i][j];
		int left = values[i] + min(getDP(values, i + 2, j), getDP(values, i + 1, j - 1));
		int right = values[j] + min(getDP(values, i, j - 2), getDP(values, i + 1, j - 1));
		F[i][j] = max(left, right);
		return F[i][j];
	}

private:
	vector<vector<int>> F;
};