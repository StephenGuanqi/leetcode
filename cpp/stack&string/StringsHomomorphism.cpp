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
	 * @param s: a string
	 * @param t: a string
	 * @return: true if the characters in s can be replaced to get t or false
	 */
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())   return false;

		vector<int> map1(256, 0);
		for (int i = 0; i < s.size(); ++i) {
			if (map1[s[i]] == 0 ) {
				map1[s[i]] = t[i];
			} else if (map1[s[i]] != t[i]) {
				return false;
			}
		}

		// abc foo
		vector<int> map2(256, 0);
		for (int i = 0; i < t.size(); ++i) {
			if (map2[t[i]] == 0) {
				map2[t[i]] = s[i];
			} else if (map2[t[i]] != s[i]) {
				return false;
			}
		}

		return true;
	}
};