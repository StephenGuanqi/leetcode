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
	/*
	 * @param n: An integer
	 * @return: An integer which is the first bad version.
	 */
	int findFirstBadVersion(int n) {
		if (n == 0) return 0;
		int left = 1, right = n;
		while (left < right) {
			int mid = left + (right - left) / 2;
//			if (SVNRepo::isBadVersion(mid))
//				right = mid;
//			else
//				left = mid + 1;
		}

		return left;
	}
};