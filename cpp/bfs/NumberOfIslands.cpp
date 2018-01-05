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
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())    return 0;
		int count = 0;
		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[0].size(); y++) {
				if (grid[x][y] == '1') {
					markGraph(grid, x, y);
					count++;
				}
			}
		}
		return count;
	}
private:
	void markGraph(vector<vector<char>>& grid, int x, int y) {
		int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int, int>> q;
		q.push({x, y});
		grid[x][y] = '0';
		while (!q.empty()) {
			auto coor = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = coor.first + d[i][0];
				int yy = coor.second + d[i][1];
				if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') {
					q.push({xx, yy});
					grid[xx][yy] = '0';
				}
			}
		}
	}

};


class Solution2 {
	/**
	 * dfs
	 */
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())    return 0;
		int count = 0;
		for (int x = 0; x < grid.size(); x++) {
			for (int y = 0; y < grid[0].size(); y++) {
				if (grid[x][y] == '1') {
					dfs(grid, x, y);
					count++;
				}
			}
		}
		return count;
	}
private:
	void dfs(vector<vector<char>>& grid, int x, int y) {
		if (x < 0 || x >= grid.size()) return;
		if (y < 0 || y >= grid[0].size())  return;
		if (grid[x][y] == '0')  return;
		grid[x][y] = '0';
		dfs(grid, x + 1, y);
		dfs(grid, x - 1, y);
		dfs(grid, x, y + 1);
		dfs(grid, x, y - 1);
	}

};