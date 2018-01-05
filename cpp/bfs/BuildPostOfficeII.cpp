//
// Created by Guanqi Yu on 12/31/17.
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
	 * @param grid: a 2D grid
	 * @return: An integer
	 */
	int shortestDistance(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty()) return -1;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dist(m, vector<int>(n));
		vector<vector<int>> visit_num(m, vector<int>(n));
		int house_num = 0;
		for (int x = 0; x != m; ++x)
			for (int y = 0; y != n; ++y)
				if (grid[x][y] == HOUSE) {
					++house_num;
					bfs(grid, x, y, dist, visit_num);
				}
		int ans = INT_MAX;
		for (int x = 0; x != m; ++x)
			for (int y = 0; y != n; ++y)
				if (grid[x][y] == EMPTY && visit_num[x][y] == house_num)
					ans = min(ans, dist[x][y]);
		return ans == INT_MAX ? -1 : ans;
	}

private:
	void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dist,
	         vector<vector<int>> &visit_num) {
		queue<pair<int, int>> q;
		// unordered_set<pair<int, int>> hash_set; no need for hash
		vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size()));
		q.push({x, y});
		flag[x][y] = 1;
		int step = 0;
		while (!q.empty()) {
			int sz = q.size();
			++step;
			for (int i = 0; i != sz; ++i) {
				auto coor = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = coor.first + diff[k][0];
					int ny = coor.second + diff[k][1];
					if (!inBound(grid, nx, ny)) continue;
					if (flag[nx][ny]) continue;
					dist[nx][ny] += step;
					visit_num[nx][ny] += 1;
					q.push({nx, ny});
					flag[nx][ny] = 1;
				}
			}
		}
	}

	bool inBound(vector<vector<int>> &grid, int x, int y) {
		return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()
		       && grid[x][y] == EMPTY;
	}

	const int diff[4][2] = {{1,  0},
	                        {-1, 0},
	                        {0,  1},
	                        {0,  -1}};
	static constexpr int HOUSE = 1;
	static constexpr int EMPTY = 0;
};

class node {
public:

	node() {}

	node(int xx, int yy, int dist) {
		x = xx;
		y = yy;
		dis = dist;
	}

	int x, y, dis;
};

class Solution2 {
public:
	/**
	 * @param grid a 2D grid
	 * @return an integer
	 */
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	bool valid(int nx, int ny, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &flag) {
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (grid[nx][ny] == 0 && flag[nx][ny] == false) {
				return true;
			}
		}
		return false;
	}

	void
	bfs(node now, vector<vector<int>> &grid, vector<vector<int>> &dis, vector<vector<int>> &visit_num, int n, int m) {
		queue<node> q;
		q.push(now);
		vector<vector<bool> > flag(n, vector<bool>(m));


		while (!q.empty()) {
			now = q.front();
			q.pop();
			visit_num[now.x][now.y]++;

			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (valid(nx, ny, n, m, grid, flag)) {
					dis[nx][ny] = dis[nx][ny] + now.dis + 1;
					flag[nx][ny] = true;
					q.push(node(nx, ny, now.dis + 1));
				}
			}
		}
	}

	int shortestDistance(vector<vector<int>> &grid) {
		// Write your code here
		if (grid.size() == 0)
			return 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dis(n, vector<int>(m, 0));
		vector<vector<int> > visit_num(n, vector<int>(m));

		int house_num = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 1) {
					house_num++;
					bfs(node(i, j, 0), grid, dis, visit_num, n, m);
				}
		}

		int ans = INT_MAX;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 0 && visit_num[i][j] == house_num) {
					ans = min(ans, dis[i][j]);
				}
		}

		return ans == INT_MAX ? -1 : ans;
	}
};
