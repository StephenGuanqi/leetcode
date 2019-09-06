//
// Created by Guanqi Yu on 1/30/18.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	struct Point {
		int x, y, val;
		Point(int x_, int y_, int val_) :
				x(x_), y(y_), val(val_) {}
	};
	/*
	 * @param A: an integer arrays sorted in ascending order
	 * @param B: an integer arrays sorted in ascending order
	 * @param k: An integer
	 * @return: An integer
	 */
	int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
		auto cmp = [](Point &p1, Point &p2) {
			return p1.val > p2.val;
		};
		priority_queue<Point, vector<Point>, decltype(cmp)> q(cmp);
		q.push({0, 0, A[0] + B[0]});
		int m = A.size(), n = B.size();
		auto visited = vector<vector<int>>(m, vector<int>(n));
		while (!q.empty()) {
			auto p = q.top(); q.pop();
			--k;
			if (k == 0)     return p.val;
			for (int j = 0; j < 2; ++j) {
				int newx = p.x + diff[j][0];
				int newy = p.y + diff[j][1];
				if (newx <= m - 1 && newy <= n - 1 && !visited[newx][newy]) {
					visited[newx][newy] = 1;
					q.push({newx, newy, A[newx] + B[newy]});
				}
			}
		}
	}

private:
	const int diff[2][2] = {{0, 1}, {1, 0}};
};