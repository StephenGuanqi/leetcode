//
// Created by Guanqi Yu on 3/17/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;



class Solution {
public:
	/**
	 * @param word1: A string
	 * @param word2: A string
	 * @return: The minimum number of steps.
	 */
	int minDistance(string &word1, string &word2) {
		// write your code here
		if (word1.empty())   return word2.size();
		if (word2.empty())   return word1.size();
		int n = word1.size(), m = word2.size();
		vector<vector<int>> f(n + 1, vector<int>(m + 1));
		// init
		for (int i = 0; i <= n; ++i) {
			f[i][0] = i;
		}
		for (int j = 0; j <= m;++j) {
			f[0][j] = j;
		}
		// dp
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				f[i][j] = min(f[i - 1][j] + 1, min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1));
				if (word1[i - 1] == word2[j - 1])
					f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
		}

		return f[n][m];
	}
};