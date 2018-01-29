//
// Created by Guanqi Yu on 1/8/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: A list of integers
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> subarraySum(vector<int> &nums) {
		unordered_map<int, int> map;
		map[0] = -1; // used for entire nums sum to zero
		vector<int> result;
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			if (map.count(sum)) {
				result.push_back(map[sum] + 1);
				result.push_back(i);
				return result;
			}
			map[sum] = i;
		}

		return result;
	}
};