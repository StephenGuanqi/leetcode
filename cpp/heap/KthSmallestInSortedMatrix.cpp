//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	struct Pos {
		int val;
		int x, y;
		Pos(int val, int x, int y) : val(val), x(x), y(y) {}
	};
	/*
	 * @param matrix: a matrix of integers
	 * @param k: An integer
	 * @return: the kth smallest number in the matrix
	 */
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		if (matrix.empty() || matrix[0].empty())    return -1;

		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		priority_queue<Pos, vector<Pos>, decltype(cmp)*> q(cmp);
		visited[0][0] = true;
		q.push(Pos(matrix[0][0], 0, 0));
		while (!q.empty()) {
			auto pos = q.top(); q.pop();
			--k;
			if (k == 0) return pos.val;
			for (int i = 0; i < 4; ++i) {
				int newx = pos.x + diff[i][0];
				int newy = pos.y + diff[i][1];
				if (!inBound(visited, newx, newy))  continue;
				visited[newx][newy] = true;
				q.push(Pos(matrix[newx][newy], newx, newy));
			}
		}
	}
private:
	static bool cmp(Pos &pos1, Pos &pos2) {
		return pos1.val > pos2.val;
	}

	bool inBound(vector<vector<bool>> &visited, int x, int y) {
		int m = visited.size();
		int n = visited[0].size();
		return x >= 0 && x < m && y >= 0 && y < n
		       && !visited[x][y];
	}
	/**
	 * we actually don't need four here. Goes from top left to right bottom
	 */
	const int diff[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
};

//int main() {
//	vector<vector<int>> matrix = {{1, 5, 7}, {3, 7, 8}, {4, 8, 9}};
//	Solution().kthSmallest(matrix, 4);
//}