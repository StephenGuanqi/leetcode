//
// Created by Guanqi Yu on 12/20/17.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



class Solution {
public:
	/**
	 * priority queue
	 * O(nlogn)
	 */
	 int findKthLargest(vector<int>& nums, int k) {
	     priority_queue<int> q(nums.cbegin(), nums.cend());
	     int result = 0;
	     for (size_t i = 0; i < k - 1; i++) {
	         q.pop();
	     }
	     return q.top();
	 }

	/**
	 * selection sort, average O(n), T(n) = T(n/2) + O(n)
	 * worst case:  T(n) = T(n - 1) + O(n) and the complexity will be O(n^2)
	 */
     int partition(vector<int>& nums, int left, int right) {
         int pivot = nums[left];
         int i = left + 1;
         for (int j = left + 1; j<= right; j++) {
             if (nums[j] > pivot) {
                 swap(nums[i], nums[j]);
                 i++;
             }
         }
         swap(nums[left], nums[i - 1]);
         return i - 1;
         // int pivot = nums[left];
         // int l = left + 1, r = right;
         // while (l <= r) {
         //     if (nums[l] < pivot && nums[r] > pivot)
         //         swap(nums[l++], nums[r--]);
         //     if (nums[l] >= pivot) l++;
         //     if (nums[r] <= pivot) r--;
         // }
         // swap(nums[left], nums[r]);
         // return r;
     }

     int findKthLargest2(vector<int>& nums, int k) {
         int l = 0, r = nums.size() - 1;
         while (true) {
             int pos = partition(nums, l, r);
             if (pos < k - 1) l = pos + 1;
             else if (pos > k - 1) r = pos - 1;
             else return nums[pos];
         }
     }

	/**
	 * heap sort
	 * O(n + klogn)
	 */
	inline int left(int index)
	{
		return (index << 1) + 1;
	}

	inline int right(int index)
	{
		return (index << 1) + 2;
	}

	int findKthLargest3(vector<int>& nums, int k)
	{
		build_heap(nums);
		// heap_size = nums.size(); // can't put here, otherwise heapify will have wrong heap_size value
		for (int i = 0; i < k; i++)
		{
			swap(nums[0], nums[heap_size - 1]);
			heap_size--;
			max_heapify(nums, 0);
		}
		return nums[heap_size];
	}

	void build_heap(vector<int> &nums)
	{
		heap_size = nums.size();
		for (int i = (heap_size >> 1) - 1; i >= 0; i--) {
			max_heapify(nums, i);
		}
	}

	void max_heapify(vector<int> &nums, int index)
	{
		int l = left(index), r = right(index);
		int largest = index;
		if (l < heap_size && nums[l] > nums[largest])    largest = l;
		if (r < heap_size && nums[r] > nums[largest])    largest = r;
		// find the biggest among three, if the index is current index, do nothing
		if (largest != index)
		{
			swap(nums[largest], nums[index]);
			max_heapify(nums, largest);
		}
	}

private:
	int heap_size;

};


class Solution2 {
	/**
	 * nlogk
	 */
public:
	/*
	 * @param n: An integer
	 * @param nums: An array
	 * @return: the Kth largest element
	 */
	int kthLargestElement(int k, vector<int> &nums) {
		// min heap
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto num : nums) {
			if (q.size() < k)
				q.push(num);
			else if (q.top() < num) {
				q.pop();
				q.push(num);
			}
		}
		return q.top();
	}
};