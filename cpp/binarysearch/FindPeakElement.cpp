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
	 * @param A: An integers array.
	 * @return: return any of peek positions.
	 */
	int findPeak(vector<int>& A) {
		int l = 0, r = A.size() - 1;
		while (l + 1 < r) {
			int mid = l + (r - l) / 2;
			if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
				return mid;
			else if (A[mid - 1] < A[mid])
				l = mid + 1;
			else if (A[mid] > A[mid + 1])
				r = mid - 1;
			else
				l = mid + 1;
		}
		if (A[l] > A[r])    return l;
		return r;
	}
};


class Solution2 {
public:
	/*
	 * @param A: An integers array.
	 * @return: return any of peek positions.
	 */
	int findPeak(vector<int>& A) {
		int l = 0, r = A.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
				return mid;
			else if (A[mid - 1] < A[mid])
				l = mid + 1;
			else if (A[mid] > A[mid + 1])
				r = mid - 1;
			else
				l = mid + 1;
		}
		// if (A[l] > A[r])    return l;
		return l;
	}
};