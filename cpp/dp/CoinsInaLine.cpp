//
// Created by Guanqi Yu on 2/24/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
	/*
	 * @param n: An integer
	 * @return: A boolean which equals to true if the first player will win
	 */
	bool firstWillWin(int n) {
		if (n == 0) return false;
		if (n == 1 || n == 2)   return true;
		vector<bool> f(n + 1);
		f[0] = false;
		f[1] = true;
		for (int i = 2; i <= n; ++i) {
			f[i] = !f[i - 1] || !f[i - 2];
		}
		return f[n];
	}
};