//
// Created by Guanqi Yu on 12/26/17.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <set>

using namespace std;


class Solution {
public:
	/**
	* set, map is implemented in BST (self-balancing red & black tree)
	* O(nlgk)
	*/
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long> window;
		/**
		 * if int, over flow when
		 * [-2147483648,-2147483647], k = 3, t = 3
		 */
		for (int i = 0; i < nums.size(); i++) {
			if (i > k)  window.erase(nums[i-k-1]);
			auto pos = window.lower_bound((long long)nums[i] - t);
			if (pos != window.end() && *pos - nums[i] <= t) return true;
			window.insert(nums[i]);
		}
		return false;
	}
};