//
// Created by Guanqi Yu on 2/1/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param heights: a matrix of integers
	 * @return: an integer
	 */
	int trapRainWater(vector<vector<int>> &heights) {
		if (heights.empty() || heights[0].empty())  return 0;
		int m = heights.size(), n = heights[0].size();
		auto visited = vector<vector<bool>>(m, vector<bool>(n));
		auto cmp = [](Point &p1,Point &p2){
			return p1.val > p2.val;
		};
		priority_queue<Point, vector<Point>, decltype(cmp)> q(cmp);
		int res = 0;
		// enqueue all out side edges and mark visited
		for (int i = 0; i < m; ++i) {
			q.push({i, 0, heights[i][0]});
			q.push({i, n - 1, heights[i][n - 1]});
			visited[i][0] = visited[i][n - 1] = true;
		}
		for (int j = 0; j < n; ++j) {
			q.push({0, j, heights[0][j]});
			q.push({m - 1, j, heights[m - 1][j]});
			visited[0][j] = visited[m - 1][j] = true;
		}
		// trappin water
		while (!q.empty()) {
			auto minp = q.top(); q.pop();
			for (int j = 0; j < 4; ++j) {
				int newx = minp.x + diff[j][0];
				int newy = minp.y + diff[j][1];
				if (newx >= 0 && newx < m && newy >= 0 && newy < n &&
				    !visited[newx][newy]) {
					visited[newx][newy] = true;
					q.push({newx, newy, max(minp.val, heights[newx][newy])});
					res += max(minp.val - heights[newx][newy], 0);
				}
			}
		}
		return res;
	}

private:
	struct Point {
		int x, y, val;
		Point(int x, int y, int val): x(x), y(y), val(val) {}
	};

	const int diff[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};