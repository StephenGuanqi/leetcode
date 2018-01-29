//
// Created by Guanqi Yu on 1/23/18.
//

#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * @param s: a string
	 * @return: an integer
	 */
	int lengthOfLongestSubstring(string &s) {
		int hash_table[256];
		int sz = s.size();
		int ans = 0, j = 0;
		for (int i = 0; i < sz; ++i) {
			while (j < sz && hash_table[s[j]] == 0) {
				ans = max(ans, j - i + 1);
				hash_table[s[j]] = 1;
				++j;
			}
			hash_table[s[i]] = 0;
			// pruning
			if (j == sz)    break;
		}
		return ans;
	}
};

//int main() {
//	string s = "aaaaaa";
//	int a = Solution().lengthOfLongestSubstring(s);
//	cout << a << endl;
//}