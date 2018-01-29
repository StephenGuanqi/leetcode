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
	 * @param x: a double
	 * @return: the square root of x
	 */
	double sqrt(double x) {
		double l = 0.0, r = x;
		double eps = 1e-12;
		if (x < 1.0) {
			l = x;
			r = 1.0;
		}
		while ((r - l) > eps) {
			double mid = l + (r - l) / 2.0;
			if (mid * mid > x)
				r = mid;
			else
				l = mid;
		}
		return l;
	}
};