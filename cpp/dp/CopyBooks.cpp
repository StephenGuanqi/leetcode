//
// Created by Guanqi Yu on 2/24/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/*
	 * @param pages: an array of integers
	 * @param k: An integer
	 * @return: an integer
	 */
	int copyBooks(vector<int> &pages, int K) {
		if (pages.empty() || K == 0)  return 0;
		int max_page = *max_element(pages.begin(), pages.end());
		if (K >= pages.size())  return max_page;

		int n = pages.size();
		vector<vector<int>> f(n, vector<int>(K, INT_MAX));
		// prefix sum
		vector<int> pref(n + 1);
		for (int i = 1; i <= n; ++i) {
			pref[i] = pref[i - 1] + pages[i - 1];
		}

		// init
		for (int i = 0; i < n; ++i) {
			f[i][0] = pref[i + 1] - pref[0];
		}
		// dp
		for (int k = 1; k < K; k++) {
			f[0][k] = pages[0];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < i; ++j) {
					int slowest = max(f[j][k - 1], pref[i + 1] - pref[j + 1]);
					f[i][k] = min(f[i][k], slowest);
				}
			}
		}

		return f[n - 1][K - 1];
	}

};