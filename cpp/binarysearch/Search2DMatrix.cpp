//
// Created by Guanqi Yu on 1/25/18.
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	/*
	 * @param matrix: matrix, a list of lists of integers
	 * @param target: An integer
	 * @return: a boolean, indicate whether matrix contains target
	 */
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty() || matrix[0].empty())    return false;
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1;
		while (l + 1 < r) {
			int mid = l + (r - l) / 2;
			int row = mid / n ;
			int col = mid % n;
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
				r = mid - 1;
			else
				l = mid + 1;
		}
		if (matrix[l / n][l % n] == target)    return true;
		if (matrix[r / n][r % n] == target)    return true;
		return false;
	}
};