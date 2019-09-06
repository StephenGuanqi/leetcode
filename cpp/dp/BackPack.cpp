//
// Created by Guanqi Yu on 2/24/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @return: The maximum size
	 */
	int backPack(int m, vector<int> A) {
		if (A.empty())  return 0;
		int n = A.size();
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
		// pre[i][j] = true  use ith item to get j total size
		// pre[i][j] = false not use ith item to get j total size
		vector<vector<bool>> pre(n + 1, vector<bool>(m + 1));
		// init
		for (int i = 0; i <= n; ++i) {
			f[i][0] = true;
		}
		// dp
		// f[i][s] = f[i - 1][s] or f[i - 1][s - a[i - 1]]
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				f[i][j] = f[i - 1][j];
				pre[i][j] = false;
				if (j >= A[i - 1]) {
					if (f[i - 1][j - A[i - 1]])
						pre[i][j] = true;
					f[i][j] = f[i][j] || f[i - 1][j - A[i - 1]];
				}
			}
		}

		int res = 0;
		for (int i = m; i >= 1; --i) {
			if (f[n][i]) {
				res = i;
				break;
			}
		}
		int i = res;
		for (int j = n; j>= 1; --j) {
			if (pre[j][i]) {
				cout << A[j - 1] << " ";
				i -= A[j - 1];
			}
		}
		cout << endl;

		return res;
	}
};