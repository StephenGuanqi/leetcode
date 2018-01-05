//
// Created by Guanqi Yu on 12/30/17.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


/**
 * Definition for a point.
 * struct Point {
 *     int x, y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
     int x, y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	/*
	 * @param grid: a chessboard included 0 (false) and 1 (true)
	 * @param source: a point
	 * @param destination: a point
	 * @return: the shortest path
	 */
	int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
		// write your code here
		if (grid.empty() || grid[0].empty())    return 0;
		int m = grid.size();
		int n = grid[0].size();
		int step = 0;
		queue<Point> q;
		q.push(source);
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				Point head = q.front(); q.pop();
				if (head.x == destination.x && head.y == destination.y)
					return step;
				for (int k = 0; k < 8; k++) {
					int x = head.x + d[k][0];
					int y = head.y + d[k][1];
					if (inBound(x, y, grid)) {
						grid[x][y] = 1;
						q.push(Point(x, y));
					}
				}
			}
			++step;
		}
		return -1;
	}
private:
	bool inBound(int x, int y, vector<vector<bool>> &grid) {
		return x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()
		       && grid[x][y] == 0;
	}
	const int d[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
};