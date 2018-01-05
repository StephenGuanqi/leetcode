//
// Created by Guanqi Yu on 12/30/17.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> edges(numCourses);
		vector<int> in_degrees(numCourses);
		vector<int> order;
		for (auto p : prerequisites) {
			edges[p.second].insert(p.first);
			++in_degrees[p.first];
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (in_degrees[i] == 0)
				q.push(i);
		}
		while (!q.empty()) {
			int t = q.front(); q.pop();
			order.push_back(t);
			for (auto neigh : edges[t]) {
				--in_degrees[neigh];
				if (in_degrees[neigh] == 0)
					q.push(neigh);
			}
		}
		if (order.size() == numCourses)
			return order;
		return {};
	}
};