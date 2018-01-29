//
// Created by Guanqi Yu on 1/10/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	/*
	 * @param s: a string,  encoded message
	 * @return: an integer, the number of ways decoding
	 */
	int numDecodings(string &s) {
		// f[i]  --> num of ways ending in ith(1 ~ n) number
		if (s.empty())  return 0;
		vector<int> f(s.size() + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= s.size(); ++i) {
			if (s[i - 1] != '0')
				f[i] += f[i - 1];
			if (i > 1) {
				int num = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
				if (num >= 10 && num <= 26)
					f[i] += f[i - 2];
			}
		}
		return f[s.size()];
	}
};