//
// Created by Guanqi Yu on 3/18/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/**
	 * @param s: A string
	 * @param p: A string includes "." and "*"
	 * @return: A boolean
	 */
	bool isMatch(string &s, string &p) {
		int n = s.size(), m = p.size();
//		bool f[n + 1][m + 1] = {{false}};
		vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
		// init
		f[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			f[i][0] = false;
		}
		// dp
		for (int j = 1; j <= m; ++j) {
			for (int i = 0; i <= n; ++i) {
				if (i >= 1 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) {
					f[i][j] = f[i - 1][j - 1]; // |=
				} else if (p[j - 1] == '*') {
					if (j <= 1) continue;
					// ....a(i)  ....(j-2)c*
					f[i][j] = f[i][j - 2]; // |=
					if (f[i][j])    continue;

					// ....(i-1)a(i)   ...a*
					if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
						f[i][j] = f[i - 1][j]; // |=
					}
				}
			}
		}

		return f[n][m];
	}
};