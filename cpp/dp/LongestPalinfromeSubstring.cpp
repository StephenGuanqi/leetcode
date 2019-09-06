//
// Created by Guanqi Yu on 3/13/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int start, end, max_len = 0;
		int n = s.size();
		// odd
		for (int c = 0; c < n; ++c) {
			int i = c, j = c;
			while (i >= 0 && j < n && s[i] == s[j]) {
				if (j - i + 1 > max_len) {
					max_len = j - i + 1;
					start = i; end = j;
				}
				--i;
				++j;
			}
		}
		// even
		for (int c = 0; c < n - 1; ++c) {
			int i = c, j = c + 1;
			while (i >= 0 && j < n && s[i] == s[j]) {
				if (j - i + 1 > max_len) {
					max_len = j - i + 1;
					start = i; end = j;
				}
				--i;
				++j;
			}
		}
		return s.substr(start, (end - start + 1));
	}

};

class Solution2 {
public:
	string longestPalindrome(string s) {
		if (s.empty())  return "";
		int n = s.size();
		int max_len, max_l, max_r;
		for (int i = 0; i < 2 * n - 1; ++i) {
			int left = i / 2;
			int right = left + i % 2;
			int len = 0;
			while (left >= 0 && right < n && s[left] == s[right]) {
				len = right - left + 1;
				if (len > max_len) {
					max_len = len;
					max_l = left;
					max_r = right;
				}
				--left;
				++right;
			}
		}
		return s.substr(max_l, max_len);
	}
};

//int main() {
//	string s = "abb";
//	cout << Solution2().longestPalindrome(s) << endl;
//}