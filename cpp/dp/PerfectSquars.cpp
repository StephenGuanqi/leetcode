//
// Created by Guanqi Yu on 1/29/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/*
	 * @param n: a positive integer
	 * @return: An integer
	 */
	int numSquares(int n) {
		if (n < 1)  return 0;
		// init
		vector<int> squares;
		auto f = vector<int>(n + 1, INT_MAX);
		for (int i = 1; i * i <= n; ++i) {
			squares.push_back(i * i);
			f[i * i] = 1;
		}
		f[0] = 0;
		if (squares.back() == n)
			return 1;
		// dp
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; squares[j] <= i; ++j) {
				// number can't sum by squares, equal to number of one
				f[i] = min(f[i - squares[j]] + 1, f[i]);
			}
		}
		// solution
		return f[n];
	}
};


class Solution2 {
public:
	/*
	 * @param n: a positive integer
	 * @return: An integer
	 */
	int numSquares(int n) {
		if (n < 1)  return 0;
		// init
		vector<int> f(n + 1, INT_MAX);
		f[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j * j <= i; ++j) {
				// each i always divide by multiple 1, so no need worry about INT_MAX overflow
				f[i] = min(f[i], f[i - j * j] + 1);
			}
		}
		return f[n];
	}
};