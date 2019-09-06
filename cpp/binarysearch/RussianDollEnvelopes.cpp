//
// Created by Guanqi Yu on 2/23/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param envelopes: a number of envelopes with widths and heights
	 * @return: the maximum number of envelopes
	 */
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		// write your code here
		if (envelopes.empty())  return 0;

		sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> int {
			if (p1.first != p2.first)
				return p1.first < p2.first;
			else
				return p1.second > p2.second;
		});

		for (auto envelop :envelopes) {
			cout << envelop.first << " " << envelop.second << endl;
		}

		// LIS problem
		vector<int> tail;
		for (int i = 0; i < envelopes.size(); ++i) {
			auto it = lower_bound(tail.begin(), tail.end(), envelopes[i].second);
			if (it == tail.end())   tail.push_back(envelopes[i].second);
			else    *it = envelopes[i].second;
		}
		return tail.size();
	}
};

