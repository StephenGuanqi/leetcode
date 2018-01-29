//
// Created by Guanqi Yu on 1/4/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
	/*
    对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1] ,
    若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
    */
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int sum = nums1.size() + nums2.size();
		if (sum & 1)
			return findKthElem(nums1, 0, nums2, 0, sum / 2 + 1);
		else
			return (findKthElem(nums1, 0, nums2, 0, sum / 2) +
			        findKthElem(nums1, 0, nums2, 0, sum / 2 + 1)) / 2.0;
	}
private:
	int findKthElem(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k) {
		// one of array already doesn't have elements, return in the next
		// [1 2]
		// [10 20 30 40 50 60 70 80 90]   k = 4
		if (start1 >= nums1.size()) return nums2[start2 + k - 1];
		if (start2 >= nums2.size()) return nums1[start1 + k - 1];
		// order is important here
		if (k == 1) return min(nums1[start1], nums2[start2]);
		// one of array elements is not enough compare with infinite and element are discarded
		// [1 2 3 4 5 6 7 8 9 10]    [1 100]
		int key1 = start1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[start1 + k / 2 - 1];
		int key2 = start2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[start2 + k / 2 - 1];
		if (key1 < key2)
			return findKthElem(nums1, start1 + k / 2, nums2, start2, k - k / 2);
		else
			return findKthElem(nums1, start1, nums2, start2 + k / 2, k - k / 2);
	}
};