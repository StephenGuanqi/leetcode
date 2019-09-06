//
// Created by Guanqi Yu on 2/13/18.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <numeric>
#include <vector>

using namespace std;

struct Interval {
	int start, end;
	Interval(int start, int end): start(start), end(end) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		if (intervals.empty())  return ans;
		sort(intervals.begin(), intervals.end(), [](Interval &i1, Interval &i2){
			return i1.start < i2.start;
		});
		int max_end = intervals[0].end;
		int cur_start = intervals[0].start;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start > max_end) {
				ans.push_back({cur_start, max_end});
				cur_start = intervals[i].start;
			}
			max_end = max(max_end, intervals[i].end);
		}
		ans.push_back({cur_start, max_end});
		return ans;
	}
};