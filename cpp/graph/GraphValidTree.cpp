//
// Created by Guanqi Yu on 12/29/17.
//
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	bool validTree(int n, vector<pair<int, int>>& edges) {
		if (n == 0) return false;
		if (edges.size() != n-1)    return false;
		// check connectivity
		vector<unordered_set<int>> graph(n);
		// step1. build graph
		for (auto edge : edges) {
			graph[edge.first].insert(edge.second);
			graph[edge.second].insert(edge.first);
		}
		// step2. bfs
		queue<int> q;
		unordered_set<int> hash_set;
		q.push(0);
		hash_set.insert(0);
		while (!q.empty()) {
			int node = q.front(); q.pop();
			for (auto neighbor : graph[node]) {
				auto ret = hash_set.insert(neighbor);
				if (ret.second)// insertion succeed, elem exist
					q.push(neighbor);
			}
		}
		return n == hash_set.size();
	}

};

class Solution2 {
	/**
	 * union find
	 */
public:
	bool validTree(int n, vector<pair<int, int>>& edges) {
		cnt = n;
		for (int i = 0; i < n; i++) {
			parent_.push_back(i);
		}
		size_.assign(n, 1);
		for (auto edge : edges) {
			if (!weightedUnion(edge.first, edge.second))
				return false;
		}
		return cnt == 1;
	}
private:
	// path compression
	int find(int x) {
		if (x != parent_[x])
			parent_[x] = find(parent_[x]);
		return parent_[x];
	}

	bool weightedUnion(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		if (rootx == rooty)     return false;
		if (size_[rootx] > size_[rooty]) {
			parent_[rooty] = rootx;
			size_[rootx] += size_[rooty];
		} else {
			parent_[rootx] = rooty;
			size_[rooty] += size_[rootx];
		}
		cnt--;
		return true;
	}

	vector<int> parent_;
	vector<int> size_;
	int cnt; // connected components amount
};