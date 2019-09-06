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
	 * @param nums: An integer array
	 * @return: The length of LIS (longest increasing subsequence)
	 */
	int longestIncreasingSubsequence(vector<int> &nums) {
		if (nums.empty())   return 0;
		vector<int> res;
		for (auto num : nums) {
			auto it = lower_bound(res.begin(), res.end(), num);
			if (it != res.end()) {
				*it = num;
			} else {
				res.push_back(num);
			}
		}
		return res.size();
	}
};
//
//int main() {
//	int array[5];
////	memset(array, 3, 5 * sizeof(int));
//	fill_n(array, 5, 3);
//	for (int i = 0; i < 5; ++i) {
//		cout << array[i] << " " << endl;
//	}
//}