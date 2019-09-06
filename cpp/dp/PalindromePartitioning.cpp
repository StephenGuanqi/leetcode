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
	 * @param s a string
	 * @return an integer
	 */
	int minCut(string s) {
		if (s.empty())  return 0;
		int n = s.size();

		// isPalindrom(i, j)
		vector<vector<bool>> isPalindrome(n, vector<bool>(n));
		int i, j, c;
		// odd length
		for (int c = 0; c < n; ++c) {
			i = j = c;
			while (i >= 0 && j < n && s[i] == s[j]) {
				isPalindrome[i][j] = true;
				--i;
				++j;
			}
		}
		// even length
		for (int c = 0; c < n - 1; ++c) {
			i = c;
			j = c + 1;
			while (i >= 0 && j < n && s[i] == s[j]) {
				isPalindrome[i][j] = true;
				--i;
				++j;
			}
		}

		// dp
		vector<int> f(n + 1, INT_MAX);
		f[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				f[i] = isPalindrome[j][i - 1] ? min(f[i], f[j] + 1) : f[i];
			}
		}

		return f[n] - 1;
	}
};

