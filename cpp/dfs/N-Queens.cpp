//
// Created by Guanqi Yu on 1/2/18.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
	/**
	 * permutation. if n = 4:
	 * [2, 4, 1, 3]
	 * but not [1, 2, 3, 4]  ---> diagnal arttack
	 */
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<int> cols;
		if (n <= 0) return result;
		dfs(result, cols, n);
		return result;
	}
private:
	// cols store n col indexes
	// search all possible col indexes and store results in res
	void dfs(vector<vector<string>> &res, vector<int> &cols, int n) {
		if (cols.size() == n) {
			res.push_back(drawChess(cols, n));
			return;
		}
		for (int i = 0; i < n; ++i) {
			if (!isValid(cols, i)) continue;
			cols.push_back(i);
			dfs(res, cols, n);
			cols.pop_back();
		}
	}

	bool isValid(vector<int> &cols, int colIdx) {
		for (int rowIdx = 0; rowIdx < cols.size(); ++rowIdx) {
			if (cols[rowIdx] == colIdx) return false;
			if (rowIdx + cols[rowIdx] == cols.size() + colIdx)  return false;
			if (rowIdx - cols[rowIdx] == cols.size() - colIdx)  return false;
		}
		return true;
	}

	vector<string> drawChess(vector<int> &cols, int n) {
		vector<string> result;
		for (auto colIdx : cols) {
			string rowstr(n, '.');
			rowstr[colIdx] = 'Q';
			result.push_back(rowstr);
		}
		return result;
	}
};