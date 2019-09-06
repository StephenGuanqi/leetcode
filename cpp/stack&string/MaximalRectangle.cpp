//
// Created by Guanqi Yu on 2/11/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	/*
	 * @param matrix: a boolean 2D matrix
	 * @return: an integer
	 */
	int maximalRectangle(vector<vector<bool>> &matrix) {
		if (matrix.empty() || matrix[0].empty())    return 0;
		int m = matrix.size(), n = matrix[0].size();
		// accumulate histogram on rows
		vector<vector<int>> heights(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j]) {
					heights[i][j] = i == 0 ? 1 : heights[i - 1][j] + 1;
				} else {
					heights[i][j] = 0;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < m; ++i) {
			int area = maxRecInHist(heights[i]);
			res = max(res, area);
		}
		return res;
	}

private:
	int maxRecInHist(vector<int> &height) {
		height.push_back(0);
		stack<int> st; // index
		int i = 0;
		int res = 0;
		while (i < height.size()) {
			if (st.empty() || height[i] >= height[st.top()]) {
				st.push(i++);
			} else {
				int cur_ind = st.top();
				st.pop();
				int h = height[cur_ind];
				int w = st.empty() ? i : i - st.top() - 1;
				res = max(res, h * w);
			}
		}
		return res;
	}
};