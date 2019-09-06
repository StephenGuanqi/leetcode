//
// Created by Guanqi Yu on 5/2/18.
//


#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		unordered_map<int, vector<pair<int, int>>> graph;
		for (auto &edge : times) {
			int u = edge[0], v = edge[1], w = edge[2];
			graph[u].emplace_back(v, w);
		}

		auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {
			return p1.second > p2.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> dist(cmp);
		constexpr int MAX_TIME = 101 * 100;
		dist.push({K, 0});

		unordered_map<int,int> min_dist;
		while (!dist.empty()) {
			// one minimum
			auto current = dist.top();
			dist.pop();
			int node = current.first, d = current.second;
			if (min_dist.count(node))   continue;
			min_dist[node] = d;
			for (auto &edge : graph[node]) {
				int nei = edge.first, weight = edge.second;
				if (min_dist.count(nei))    continue;
				dist.push({nei, d + weight});
			}
		}

		if (min_dist.size() != N)   return -1;
		int res = 0;
		for (auto &p : min_dist) {
			res = max(res, p.second);
		}
		return res;
	}
};

int main() {
	vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	int N = 4, K = 2;
	Solution().networkDelayTime(times, N, K);
}