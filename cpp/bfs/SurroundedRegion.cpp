//
// Created by Guanqi Yu on 1/31/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	/*
	 * @param board: board a 2D board containing 'X' and 'O'
	 * @return: nothing
	 */
	void surroundedRegions(vector<vector<char>> &board) {
		if (board.empty() || board[0].empty())  return;
		m = board.size();
		n = board[0].size();
		// 4 edges
		for (int i = 0; i < m; ++i)  {
			if (board[i][0] == 'O')
				bfsMark(board, i, 0);
			if (board[i][n - 1] == 'O')
				bfsMark(board, i, n - 1);
		}
		for (int j = 0; j < n; ++j) {
			if (board[0][j] == 'O')
				bfsMark(board, 0, j);
			if (board[m - 1][j] == 'O')
				bfsMark(board, m - 1, j);
		}
		// mark surrounded region
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 'W')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
			}
		}
	}

private:
	// mark '0' to 'W'
	void bfsMark(vector<vector<char>> &board, int x, int y) {
		queue<pair<int, int>> q;
		q.push({x, y});
		board[x][y] = 'W';
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			for (int j = 0; j < 4; ++j) {
				int newx = p.first + diff[j][0];
				int newy = p.second + diff[j][1];
				if (newx >= 0 && newx < m && newy >= 0 && newy < n
				    && board[newx][newy] == 'O') {
					board[newx][newy] = 'W';
					q.push({newx, newy});
				}
			}
		}
	}

	int m, n;
	const int diff[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
