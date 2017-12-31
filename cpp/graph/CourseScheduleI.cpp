//
// Created by Guanqi Yu on 12/30/17.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
	/**
	* For each node, decrease its neighbor's indegree by one
	* similar to directed graph's level order traversal
	*/
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> edges(numCourses); // should be unordered_set here
		vector<int> in_degrees(numCourses);
		for (auto p : prerequisites) {
			edges[p.second].push_back(p.first);
			++in_degrees[p.first];
		}
		// find all starting courses with 0 indegree
		queue<int> q;
		for (int i = 0; i != numCourses; ++i)
			if (in_degrees[i] == 0)
				q.push(i);
		int count = 0;
		// bfs topological sort
		while (!q.empty()) {
			int t = q.front(); q.pop();
			++count;
			for (auto nei : edges[t]) {
				--in_degrees[nei];
				if (in_degrees[nei] == 0) {
					q.push(nei);
				}
			}
		}
		return count == numCourses;
	}
};