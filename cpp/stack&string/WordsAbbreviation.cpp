//
// Created by Guanqi Yu on 1/10/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param dict: an array of n distinct non-empty strings
	 * @return: an array of minimal possible abbreviations for every word
	 */
	vector<string> wordsAbbreviation(vector<string> &dict) {
		bool unique = false;
		vector<int> prefix(dict.size(), 1);
		vector<string> ans(dict.size());
		unordered_map<string, int> abbrev_count;
		for (int i = 0; i < dict.size(); ++i) {
			ans[i] = getabrrev(dict[i], 1);
			abbrev_count[ans[i]] += 1;
		}
		while (true) {
			unique = true;
			for (int i = 0; i < dict.size(); ++i) {
				if (abbrev_count[ans[i]] > 1) {
					prefix[i]++;
					ans[i] = getabrrev(dict[i], prefix[i]);
					abbrev_count[ans[i]] += 1;
					unique = false;
				}
			}
			if (unique) break;
		}
		return ans;
	}

private:
	// return abbreviation string start from the pth prefix
	// all p's initial value is 1
	string getabrrev(string &s, int p) {
		if (p >= s.size() - 2) {
			return s;
		}
		return s.substr(0, p) + to_string(s.size() - p - 1) + s.back();
	}
};