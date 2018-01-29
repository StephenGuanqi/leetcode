//
// Created by Guanqi Yu on 1/8/18.
//
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
	/**
	 * best case O(n + L!)
	 * worst case O(nL!)
	 * time out!!!!!
	 */
public:
	/*
	 * @param strs: A list of strings
	 * @return: A list of strings
	 */
	vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		unordered_set<string> origins;
		if (strs.empty())   return {};
		// {anagram, original string}
		unordered_map<string, string> map;
		for (auto str : strs) {
			if (map.count(str)) {
				ans.push_back(str);
				origins.insert(map[str]);
			}
			addAnagrams(map, str);
		}
		for (auto origin : origins) {
			ans.push_back(origin);
		}
		return ans;
	}

private:
	void addAnagrams(unordered_map<string, string> &map, string &str) {
		vector<string> result;
		vector<char> path;
		vector<bool> visited(str.size());
		stringPermutation(result, path, visited, str);
		for (string anagram : result) {
			map[anagram] = str;
		}
	}

	void stringPermutation(vector<string> &res, vector<char> &path,
	                       vector<bool> &visited, string &str) {
		if (path.size() == str.size()) {
			res.emplace_back(path.begin(), path.end());
			return;
		}
		for (int i = 0; i < str.size(); ++i) {
			if (visited[i]) continue;
			if (!visited[i] && i != 0 && str[i] == str[i - 1])  continue;
			path.push_back(str[i]);
			visited[i] = true;
			stringPermutation(res, path, visited, str);
			visited[i] = false;
			path.pop_back();
		}
	}
};

//int main() {
//	vector<string> vecs = {"tea", "and", "ate", "eat", "den"};
//	Solution().anagrams(vecs);
//}


class Solutio2n {
	/**
	 * if for each string, sort it and use it as key, O(nLlogL)
	 * or we can just count the 26 char, and use its hash as key in hash_table
	 * or (hash function is hard to guanrantee), using thought of counting sort,
	 * we can recover the sorted string from the count array
	 **/
public:
	/*
	 * @param strs: A list of strings
	 * @return: A list of strings
	 */
	vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		if (strs.empty())   return {};
		// {sortedstring, nagrams}
		unordered_map<string, vector<string>> map;
		for (auto str : strs) {
			string key = getSortedString(str);
			map[key].push_back(str);
		}
		for (auto entry : map) {
			if (entry.second.size() > 1)
				ans.insert(ans.end(),
				           entry.second.begin(), entry.second.end());
		}
		return ans;
	}
private:
	string getSortedString(string &str) {
		vector<int> counts(26);
		for (char c : str) {
			counts[c - 'a']++;
		}
		string res;
		for (int i = 0; i < 26; ++i) {
			while (counts[i]-- > 0)
				res += (char)('a' + i);
		}
		return res;
	}
};