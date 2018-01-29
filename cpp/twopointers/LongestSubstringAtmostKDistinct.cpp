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
	 * @param s: A string
	 * @param k: An integer
	 * @return: An integer
	 */
	int lengthOfLongestSubstringKDistinct(string &s, int k) {
		unordered_map<char, int> map;
		int ans = 0, j = 0;
		for (int i = 0; i < s.size(); ++i) {
			while (j < s.size()) {
				if (map.count(s[j]))
					++map[s[j]];
				else {
					if (map.size() == k)
						break;
					map[s[j]] = 1;
				}
				++j;
			}
			ans = max(ans, j - i);
			if (map[s[i]] > 1)
				--map[s[i]];
			else
				map.erase(s[i]);
		}
		return ans;
	}
};

