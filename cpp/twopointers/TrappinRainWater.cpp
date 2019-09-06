//
// Created by Guanqi Yu on 2/1/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param heights: a list of integers
	 * @return: a integer
	 */
	int trapRainWater(vector<int> &heights) {
		if (heights.empty())    return 0;
		int i = 0, j = heights.size() - 1;
		int leftMax = heights.front();
		int rightMax = heights.back();
		int res = 0;
		while (i <= j) {
			if (leftMax < rightMax) {
				if (heights[i] > leftMax)
					leftMax = heights[i];
				else
					res += leftMax - heights[i];
				++i;
			} else {
				if (heights[j] > rightMax)
					rightMax = heights[j];
				else
					res += rightMax - heights[j];
				--j;
			}
		}
		return res;
	}
};