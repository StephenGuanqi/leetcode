//
// Created by Guanqi Yu on 3/23/18.
//
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, unordered_map<string, double>> G;
		for (int i = 0; i < equations.size(); ++i) {
			string from = equations[i].first, to = equations[i].second;
			double val = values[i];
			G[from][to] = val;
			if (val != 0)
				G[to][from] = 1 / val;
		}
//		string s1 = "b";
//		string s2 = "c";
//		cout << G[s1][s2] << endl;
//		cout << (G[s1].count(s2) > 0 ? "true" : "false") << endl;
		vector<double> ans;
		for (const auto &q : queries) {
			unordered_set<string> visited;
			ans.push_back(dfs(G, visited, q.first, q.second));
		}
		return ans;
	}

private:
	double dfs(unordered_map<string, unordered_map<string, double>> G,
	           unordered_set<string> &visited,
	           string start, string end) {
		if (G.count(start) == 0)
			return -1;
		if (G[start].count(end) > 0)
			return G[start][end];
		visited.insert(start);
		for (auto &elem : G[start]) {
			string nei = elem.first;
			double wei = elem.second;
			if (visited.count(nei) > 0) continue;
			double val = dfs(G, visited, nei, end);
			if (val != -1)  return val * wei;
		}
		visited.erase(start);
		return -1;
	}

};
//
//int main() {
//	vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
//	vector<double> values = {2, 3};
//	vector<pair<string, string>> queries = {{"a", "c"}, {"b", "a"}};
//	Solution().calcEquation(equations, values, queries);
//}