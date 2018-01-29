//
// Created by Guanqi Yu on 1/24/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	/**
	 * @param nums: The integer array.
	 * @param target: Target number to find.
	 * @return: The first position of target. Position starts from 0.
	 */
	int binarySearch(vector<int> &array, int target) {
		// write your code here
		int low = 0, high = array.size() - 1;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (array[mid] == target)
				high = mid;
			else if (array[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (array[low] == target)
			return low;
		return -1;
	}
};