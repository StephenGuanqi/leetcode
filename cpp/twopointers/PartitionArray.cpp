//
// Created by Guanqi Yu on 1/4/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: The integer array you should partition
	 * @param k: An integer
	 * @return: The index after partition
	 */
	int partitionArray(vector<int> &nums, int k) {
		if (nums.empty())   return 0;
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			while (left < right && nums[left] < k) left++;
			while (left < right && nums[right] >= k) right--;
			if (left < right) {
				swap(nums[left++], nums[right--]);
			}
		}
		if (nums[left] < k) return left + 1;
		return left;
	}
};

class Solution2 {
public:
	/*
	 * @param nums: The integer array you should partition
	 * @param k: An integer
	 * @return: The index after partition
	 */
	int partitionArray(vector<int> &nums, int k) {
		if (nums.empty())   return 0;
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			while (left <= right && nums[left] < k) left++;
			while (left <= right && nums[right] >= k) right--;
			if (left <= right) {
				swap(nums[left++], nums[right--]);
			}
		}
		return left;
	}
};