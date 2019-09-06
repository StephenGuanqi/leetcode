//
// Created by Guanqi Yu on 2/13/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <numeric>

using namespace std;

struct Interval {
	int start, end;
	Interval(int start, int end): start(start), end(end) {}
};

class Solution {
public:
	/*
	 * @param airplanes: An interval array
	 * @return: Count of airplanes are in the sky.
	 */
	int countOfAirplanes(vector<Interval> &airplanes) {
		if (airplanes.empty())  return 0;
		vector<pair<int, int>> vec;
		for (auto &interval : airplanes) {
			vec.push_back({interval.start, 1});
			vec.push_back({interval.end, 0});
		}
		sort(vec.begin(), vec.end(), [](pair<int, int> &p1, pair<int, int> &p2)->int {
			if (p1.first != p2.first)
				return p1.first < p2.first;
			else
				return p1.second < p2.second;
		});
		int res = 0;
		int count = 0;
		for (auto &p : vec) {
			if (p.second) {
				++count;
				res = max(res, count);
			} else {
				--count;
			}
		}
		return res;
	}
};