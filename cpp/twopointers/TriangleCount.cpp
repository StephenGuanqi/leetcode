//
// Created by Guanqi Yu on 1/5/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
	/**
	 * O (n ^ 2)
	 */
public:
	/*
	 * @param S: A list of integers
	 * @return: An integer
	 */
	int triangleCount(vector<int> &S) {
		if (S.empty())  return 0;
		int ans = 0;
		sort(S.begin(), S.end());
		for (int i = 0; i < S.size(); ++i) {
			int left = 0, right = i - 1;
			while (left < right) {
				int sum = S[left] + S[right];
				if (sum > S[i]) {
					ans += right - left;
					--right;
				} else {
					++left;
				}
			}
		}
		return ans;
	}
};