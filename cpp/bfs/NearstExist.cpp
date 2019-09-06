//
// Created by Guanqi Yu on 1/31/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * @param rooms: m x n 2D grid
	 * @return: nothing
	 */
	void wallsAndGates(vector<vector<int>> &rooms) {
		if (rooms.empty() || rooms[0].empty())  return;
		m = rooms.size();
		n = rooms[0].size();
		// find all gates at the beginning
		queue<pair<int, int>> q;
		auto visited = vector<vector<bool>>(m, vector<bool>(n));
		for (int i = 0 ; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (rooms[i][j] == GATE) {
					q.push({i, j});
					visited[i][j] = true;
				}
			}
		}
		// level order bfs
		int level = 0;
		while (!q.empty()) {
			int sz = q.size();
			++level;
			for (int i = 0; i < sz; ++i) {
				auto p = q.front(); q.pop();
				for (int j = 0; j < 4; ++j) {
					int newx = p.first + diff[j][0];
					int newy = p.second + diff[j][1];
					if (!inBound(visited, rooms, newx, newy))  continue;
					rooms[newx][newy] = level;
					visited[newx][newy] = true;
					q.push({newx, newy});
				}
			}
		}
	}

private:
	bool inBound(vector<vector<bool>> &visited, vector<vector<int>> &rooms,
	             int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n &&
		       !visited[x][y] && rooms[x][y] != WALL;
	}

	int m, n;
	const int GATE = 0;
	const int WALL = -1;
	const int diff[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
};