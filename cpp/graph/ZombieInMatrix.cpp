//
// Created by Guanqi Yu on 12/30/17.
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
	 * @param grid: a 2D integer grid
	 * @return: an integer
	 */
	int zombie(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty())    return 0;
		// get all initial zombies' position and count initial people's amount
		queue<pair<int, int>> q;
		int people_count = 0;
		for (int x = 0; x < grid.size(); x++)
			for (int y = 0; y < grid[0].size(); y++)
				if (grid[x][y] == ZOMBIE)
					q.push({x, y});
				else if (grid[x][y] == PEOPLE)
					++people_count;
		int days = 0;
		// level order bfs to count days
		while (!q.empty()) {
			days++;
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				auto zombie_coor = q.front(); q.pop();
				for (int k = 0; k < 4; ++k) {
					int x = zombie_coor.first + diff[k][0];
					int y = zombie_coor.second + diff[k][1];
					if (!isPeople(grid, x, y)) continue;
					grid[x][y] = ZOMBIE;
					q.push({x, y});
					--people_count;
					/**
					 * when all people dead, the last transitioned people will still added to queue
					 */
					if (people_count == 0)
						return days;
				}
			}
		}
		return - 1;
	}
private:
	bool isPeople(vector<vector<int>> &grid, int x, int y) {
		int m = grid.size();
		int n = grid[0].size();
		return x >= 0 && x < m && y >= 0 && y < n
		       && grid[x][y] == PEOPLE;
	}

	const int WALL = 2;
	const int ZOMBIE = 1;
	const int PEOPLE = 0;
	const int diff[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main() {
	vector<vector<int>> grid = {{0,1,2,0,0}, {1,0,0,2,1}, {0,1,0,0,0}};
	cout << Solution().zombie(grid) << endl;
}