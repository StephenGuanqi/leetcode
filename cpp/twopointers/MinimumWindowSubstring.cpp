//
// Created by Guanqi Yu on 1/23/18.
//
#include <list>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
	/**
	 * O(256) for each compare
	 */
public:
	/*
	 * @param source : A string
	 * @param target: A string
	 * @return: A string denote the minimum window, return "" if there is no such a string
	 */
	string minWindow(string &source , string &target) {
		int ans = INT_MAX;
		string min_str = "";
		int j = 0;
		vector<int> source_hash(256);
		vector<int> target_hash(256);
		for (char c : target)
			target_hash[c] += 1;
		for (int i = 0; i < source.size(); ++i) {
			while (j < source.size() && !valid(source_hash, target_hash)) {
				++source_hash[source[j]];
				++j;
			}
			if (valid(source_hash, target_hash)) {
				if (ans > j - i) {
					ans = j - i;
					min_str = source.substr(i, j - i);
				}
			}
			--source_hash[source[i]];
		}
		return min_str;
	}

	bool valid(vector<int> &source_hash, vector<int> &target_hash) {
		for (int i = 0; i < 256; ++i)
			if (target_hash[i] > source_hash[i])
				return false;
		return true;
	}
};


class Solution2 {
public:
	/*
	 * @param source : A string
	 * @param target: A string
	 * @return: A string denote the minimum window, return "" if there is no such a string
	 */
	string minWindow(string &source , string &target) {
		int ans = INT_MAX;
		string min_str = "";
		int j = 0;
		vector<int> target_hash(256);
		for (char c : target)
			target_hash[c] += 1;
		int diff_count = target.size(); // number of char in target string remain
		for (int i = 0; i < source.size(); ++i) {
			while (j < source.size() && diff_count != 0) {
				if (target_hash[source[j]] > 0) --diff_count;
				--target_hash[source[j]];
				++j;
			}
			if (diff_count == 0) {
				if (ans > j - i) {
					ans = j - i;
					min_str = source.substr(i, j - i);
				}
			}
			if (target_hash[source[i]] == 0)    ++diff_count;
			++target_hash[source[i]];
		}
		return min_str;
	}
};