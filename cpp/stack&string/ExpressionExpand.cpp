//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


class Solution {
public:
	/*
	 * @param s: an expression includes numbers, letters and brackets
	 * @return: a string
	 */
	string expressionExpand(string &s) {
		string res;
		int i = 0;
		while (i < s.size()) {
			if (isdigit(s[i]))
				res += getStringRepetition(s, i);
			else
				res += s[i];
			++i;
		}
		return res;
	}

private:

	string getStringRepetition(string &s, int &starti) {
		string res;
		int times = 0;
		while (isdigit(s[starti])) {
			times = times * 10 + s[starti] - '0';
			++starti;
		}
		if (s[starti] == '[')   ++starti;
		while (starti < s.size()) {
			char c = s[starti];
			if (isdigit(c)) {
				string strs = getStringRepetition(s, starti);
				res += strs;
			} else if (c == ']')  {
				return repetString(res, times);
			}else {
				res += c;
			}
			++starti;
		}
		return res;
	}

	string repetString(string &str, int times) {
		string res;
		while (times--) {
			res += str;
		}
		return res;
	}
};