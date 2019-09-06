//
// Created by Guanqi Yu on 3/16/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
	/*
	 * @param A: An integer array
	 * @return: An integer
	 */
	int stoneGame(vector<int> &A) {
		// write your code here
		if (A.empty())  return 0;
		int n = A.size();
		vector<vector<int>> f(n, vector<int>(n, INT_MAX));

		// prefix sum
		vector<int> pref(n + 1);
		for (int i = 1; i <= n; ++i) {
			pref[i] = pref[i - 1] + A[i - 1];
		}

		// dp
		return search(f, 0, n - 1, pref);
	}

	int search(vector<vector<int>> &f, int x, int y, vector<int> &pref) {
		if (f[x][y] != INT_MAX)
			return f[x][y];
		if (x == y)     return 0;
		int val = INT_MAX;
		for (int k = x; k < y; ++k) {
			val = min(val, search(f, x, k, pref) + search(f, k + 1, y, pref) +
			               pref[y + 1] - pref[x]);
		}
		f[x][y] = val;
		return f[x][y];
	}

};