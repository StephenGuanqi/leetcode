//
// Created by Guanqi Yu on 3/10/18.
//

#include <list>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	/*
	 * @param k: An integer
	 * @param nums: An integer array
	 * @return: kth smallest element
	 */
	int kthSmallest(int k, vector<int> nums) {
		return kthSmallest(nums, k - 1, 0, nums.size() - 1);
	}

	int kthSmallest(vector<int> &nums, int k, int i, int j) {
		int pos = partition(nums, i, j);
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
		if (pos > k)
			return kthSmallest(nums, k, i, pos);
		else if (pos < k)
			return kthSmallest(nums, k - pos, pos, j);
		else
			return nums[k];
	}

	int partition(vector<int> &nums, int start, int end) {
		int &pivot = nums[start];
		++start;
		while (start <= end) {
			while (start <= end && nums[start] < pivot) ++start;
			while (start <= end && nums[end] >= pivot)  --end;
			if (start <= end) {
				swap(nums[start++], nums[end--]);
			}
		}
		swap(pivot, nums[end]);
		return end;
	}

};