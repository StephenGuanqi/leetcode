//
// Created by Guanqi Yu on 3/18/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/**
	 * @param s1: A string
	 * @param s2: A string
	 * @param s3: A string
	 * @return: Determine whether s3 is formed by interleaving of s1 and s2
	 */
	bool isInterleave(string &s1, string &s2, string &s3) {
		// write your code here
		int n = s1.size(), m = s2.size();
		if (s3.size() != n + m)     return false;
//		bool f[n + 1][m + 1] = {{false}};
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
		// init
		f[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (!f[i - 1][0])
				f[i][0] = false;
			else
				f[i][0] = s1[i - 1] == s3[i - 1];
		}
		for (int i = 1; i <= m; ++i) {
			if (!f[0][i - 1])
				f[0][i] = false;
			else
				f[0][i] = s2[i - 1] == s3[i - 1];
		}
		// dp
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				f[i][j] = f[i - 1][j] && s1[i - 1] == s3[i + j - 1]
				          || f[i][j - 1] && s2[j - 1] == s3[i + j - 1];
			}
		}

		return f[n][m];
	}
};