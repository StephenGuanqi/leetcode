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
	 * @param matrix: A list of lists of integers
	 * @param target: An integer you want to search in matrix
	 * @return: An integer indicate the total occurrence of target in the given matrix
	 */
	int searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty() || matrix[0].empty())    return 0;
		int m = matrix.size(), n = matrix[0].size();
		int y = m - 1, x = 0;
		int count = 0;
		while (y >= 0 && x <= n - 1) {
			int cur = matrix[y][x];
			if (cur > target)
				--y;
			else if (cur < target)
				++x;
			else {
				++count;
				--y;
				++x;
			}
		}
		return count;
	}
};