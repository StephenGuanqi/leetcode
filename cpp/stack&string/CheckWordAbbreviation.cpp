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
	 * @param word: a non-empty string
	 * @param abbr: an abbreviation
	 * @return: true if string matches with the given abbr or false
	 */
	bool validWordAbbreviation(string word, string abbr) {
		int i = 0, j = 0;
		while (i < word.size() && j < abbr.size()) {
			if (isdigit(abbr[j])) {
				if (abbr[j] == '0') return false;
				int num = 0;
				while (j < abbr.size() && isdigit(abbr[j]))
					num = 10 * num + abbr[j++] - '0';
				i += num;
			} else if (word[i++] != abbr[j++])
				return  false;
		}
		return i == word.size() && j == abbr.size();
	}
};

//int main() {
//	string word = "internationalization";
//	string abbrev = "i12iz4n";
//	Solution().validWordAbbreviation(word, abbrev);
//}