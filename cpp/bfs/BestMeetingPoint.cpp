//
// Created by Guanqi Yu on 4/14/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())    return -1;
		m = grid.size();
		n = grid[0].size();
		vector<vector<int>> dist(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1)
					bfs(grid, i, j, dist);
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = min(ans, dist[i][j]);
			}
		}
		return ans;
	}

private:
	void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dist) {
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		queue<pair<int, int>> q;
		visited[x][y] = true;
		q.emplace(x, y);
		int steps = 0;
		while (!q.empty()) {
			++steps;
			int sz = q.size();
			for (int i = 0; i < sz; ++i) {
				auto coor = q.front(); q.pop();
				for (int j = 0; j < 4; ++j) {
					int xx = coor.first + diff[j][0];
					int yy = coor.second + diff[j][1];
					if (xx < 0 || yy < 0 || xx >= m || yy >= n
					    || visited[xx][yy] || grid[xx][yy] == PEOPLE)
						continue;
					visited[xx][yy] = true;
					dist[xx][yy] += steps;
					q.emplace(xx, yy);
				}
			}
		}
	}

	int m, n;
	const int diff[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
	constexpr static int PEOPLE = 1;
};
//
//int main() {
//	vector<vector<int>> grid = {{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
//	cout << Solution().minTotalDistance(grid) << endl;
//}