//
// Created by Guanqi Yu on 1/25/18.
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
	/*
	 * @param A: an integer rotated sorted array
	 * @param target: an integer to be searched
	 * @return: an integer
	 */
	int search(vector<int> &A, int target) {
		if (A.empty())  return -1;
		int l = 0, r = A.size() - 1;
		while (l + 1 < r) {
			int mid = l + (r - l) / 2;
			if (A[mid] == target)   return mid;
			if (A[mid] > A.front()) {
				if (A.front() <= target && target < A[mid])
					r = mid - 1;
				else
					l = mid + 1;
			} else {
				if (A[mid] < target && target <= A.back())
					l = mid + 1;
				else
					r = mid - 1;
			}
		}

		if (A[l] == target) return l;
		if (A[r] == target) return r;
		return -1;
	}
};