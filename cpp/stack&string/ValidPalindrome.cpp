//
// Created by Guanqi Yu on 1/23/18.
//

#include <list>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	/*
	 * @param s: A string
	 * @return: Whether the string is a valid palindrome
	 */
	bool isPalindrome(string &s) {
		if (s.empty())  return true;
		int left = 0, right = s.size() - 1;
		while (left <= right) {
			while (left <= right && !isalnum(s[left]))    ++left;
			while (left <= right && !isalnum(s[right]))    --right;
			if (left <= right && tolower(s[left++]) != tolower(s[right--]))
				return false;
		}
		return true;
	}
};

//int main() {
//	string s = "a ba";
//	Solution().isPalindrome(s);
//}