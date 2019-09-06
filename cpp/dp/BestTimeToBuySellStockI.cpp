//
// Created by Guanqi Yu on 2/22/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	/**
	 * @param prices: Given an integer array
	 * @return: Maximum profit
	 */
	int maxProfit(vector<int> &prices) {
		// write your code here
		if (prices.empty()) return 0;
		int ans = 0;
		int lowest = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			ans = max(ans, prices[i] - lowest);
			lowest = min(lowest, prices[i]);
		}
		return ans;
	}
};