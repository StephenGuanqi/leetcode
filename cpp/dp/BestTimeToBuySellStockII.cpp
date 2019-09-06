//
// Created by Guanqi Yu on 2/22/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	/**
	 * @param prices: Given an integer array
	 * @return: Maximum profit
	 */
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) return 0;
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		}
		return res;
	}
};