//
// Created by Guanqi Yu on 2/14/18.
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
	/*
	 * @param coins: a list of integer
	 * @param amount: a total amount of money amount
	 * @return: the fewest number of coins that you need to make up
	 */
	int coinChange(vector<int> &coins, int amount) {
		if (coins.empty())  return 0;
		int n = coins.size();
		vector<int> f(amount + 1, INT_MAX);
		f[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i >= coins[j] && f[i - coins[j]] != INT_MAX) {
					f[i] = min(f[i], f[i - coins[j]] + 1); // prevent over flow
				}
			}
			cout << i << " " << f[i] << endl;
		}
		if (f[amount] == INT_MAX)
			return -1;
		return f[amount];
	}

};