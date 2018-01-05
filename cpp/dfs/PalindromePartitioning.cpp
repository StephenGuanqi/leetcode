//
// Created by Guanqi Yu on 1/1/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	/**
	 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

	 # of partition solution   ---> combination or subset

	 loop through the string, check if substr(0, i) is palindrome. If it is, recursively call dfs() on the rest of
	 sub string: substr(i+1, length). keep the current palindrome partition so far in the ‘path’ argument of dfs().
	 When reaching the end of string, add current partition in the result.

	 */

public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> results;
		vector<string> partitions;
		dfs(s, partitions, results, 0);
		return results;
	}
private:
	void dfs(const string &s, vector<string> &partitions, vector<vector<string>> &res,
	         int startIdx) {
		if (startIdx == s.size()) {
			res.push_back(partitions);
			return;
		}
		for (int i = startIdx; i < s.size(); ++i) {
			string subs = s.substr(startIdx, (i - startIdx) + 1);
			if (!isPalindrom(subs)) continue;
			partitions.push_back(subs);
			dfs(s, partitions, res, i + 1);
			partitions.pop_back();
		}
	}

	bool isPalindrom(const string &s) {
		return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
	}

};