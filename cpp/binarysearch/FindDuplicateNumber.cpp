//
// Created by Guanqi Yu on 2/12/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: an array containing n + 1 integers which is between 1 and n
	 * @return: the duplicate one
	 */
	int findDuplicate(vector<int> &nums) {
		int start = 1;
		int end = nums.size() - 1; // solution range
		while (start + 1 <  end) {
			int mid = start + (end - start) / 2;
			if (checkSmallerNum(nums, mid) <= mid) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
		if (checkSmallerNum(nums, start) <= start)
			return end;
		return start;
	}

	int checkSmallerNum(vector<int> &nums, int mid) {
		int amount = 0;
		for (auto num : nums) {
			if (num <= mid)
				amount++;
		}
		return amount;
	}
};