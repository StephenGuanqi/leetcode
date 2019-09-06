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
	 * @param height: A list of integer
	 * @return: The area of largest rectangle in the histogram
	 */
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 1) return height[0];
		// monocular stack, store increasing number
		stack<pair<int, int>> st; // {index, height}
		st.push({0, 0});
		int res = 0;
		for (int i = 0; i < height.size(); ++i) {
			if (height[i] >= st.top().second) {
				st.push({i + 1, height[i]});
			} else {
				while (height[i] < st.top().second) {
					auto cur_top = st.top();
					st.pop();
					int cur_area = (i - st.top().first) * cur_top.second;
					res = max(res, cur_area);
				}
				st.push({i + 1, height[i]});
			}
		}
		// add final dumy 0
		while (st.top().second > 0) {
			auto cur_top = st.top();
			st.pop();
			int cur_area = (height.size() - st.top().first) * cur_top.second;
			res = max(res, cur_area);
		}
		return res;
	}
};