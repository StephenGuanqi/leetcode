//
// Created by Guanqi Yu on 3/29/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string alienOrder(vector<string>& words) {
		unordered_map<char, unordered_set<char>> graph; // directed
		unordered_map<char, int> indegrees;
		for (auto &word : words) {
			for (auto &c : word) {
				indegrees[c] = 0;
			}
		}
		for (int i = 0; i < words.size() - 1; ++i) {
			string word1 = words[i];
			string word2 = words[i + 1];
			int sz = min(word1.size(), word2.size());
			for (int i = 0; i < sz; ++i) {
				char c1 = word1[i], c2 = word2[i];
				if (c1 != c2) {
					// insert edges in graph
					graph[c1].insert(c2);
					indegrees[c2] += 1;
					break;
				}
			}
		}
		// topological sort
		string res;
		queue<char> q;
		for (auto p : indegrees) {
			if (p.second == 0)    q.push(p.first);
		}
		while (!q.empty()) {
			auto c = q.front(); q.pop();
			res.push_back(c);
			for (auto nei : graph[c]) {
				--indegrees[nei];
				if (indegrees[nei] == 0)
					q.push(nei);
			}
		}
		if (res.size() != indegrees.size()) {
			cout << res << endl;
			return "";
		}
		return res;
	}
};

//int main() {
//	vector<string> words = {"za","zb","ca","cb"};
//	Solution().alienOrder(words);
//}