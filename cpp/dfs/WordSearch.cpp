//
// Created by Guanqi Yu on 1/31/18.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

using namespace std;


class Solution {
public:
	/*
	 * @param board: A list of lists of character
	 * @param word: A string
	 * @return: A boolean
	 */
	bool exist(vector<vector<char>> &board, string &word) {
		if (board.empty() || board[0].empty())  return false;
		if (word.empty())   return true;
		m = board.size();
		n = board[0].size();
		bool ans = false;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == word[0])
					ans = dfs(board, i, j, 0, word);
				if (ans)    return ans;
			}
		}
		return ans;
	}

	bool dfs(vector<vector<char>> &board, int x, int y, int startIndex, string &word) {
		if (startIndex == word.size() - 1)  return true;
		bool res = false;
		board[x][y] = '#';
		for(int j = 0; j < 4; ++j) {
			int newx = x + diff[j][0];
			int newy = y + diff[j][1];
			if (newx >= 0 && newx < m && newy >= 0 && newy < n &&
			    board[newx][newy] != '#' && board[newx][newy] == word[startIndex + 1]) {
				res = dfs(board, newx, newy, startIndex + 1, word);
				if (res)    break;
			}
		}
		board[x][y] = word[startIndex];
		return res;
	}

	int m, n;
	const int diff[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
};