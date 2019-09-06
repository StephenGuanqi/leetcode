//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

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

class Solution2 {
public:
	/*
	 * @param s: an expression includes numbers, letters and brackets
	 * @return: a string
	 */
	// we have to store the information in stack, including added string and repet count
	// for Java we can use Object, for c++ we have to use two stacks to store char and num
	string expressionExpand(string &s) {
		if (s.empty())  return "";
		stack<string> st;
		stack<int> stnum;
		int number = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (isdigit(s[i])) {
				number = number * 10 + s[i] - '0';
			} else if (s[i] == '[') {
				stnum.push(number);
				st.push(string(1, '['));
				number = 0;
			} else if (s[i] == ']') {
				string news = popStack(st);
				int count = stnum.top();
				stnum.pop();
				for (int i = 0; i < count; ++i) {
					st.push(news);
				}
			} else {
				st.push(string(1, s[i]));
			}
		}
		return popStack(st);
	}

private:
	string popStack(stack<string> &st) {
		stack<string> buffer;
		while (!st.empty() && st.top() != "[") {
			buffer.push(st.top());
			st.pop();
		}
		if (!st.empty() && st.top() == "[")
			st.pop();
		string res;
		while (!buffer.empty()) {
			res += buffer.top();
			buffer.pop();
		}
		return res;
	}
};