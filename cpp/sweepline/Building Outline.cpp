//
// Created by Guanqi Yu on 2/13/18.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
using namespace std;


class Solution {
public:
	/*
	 * @param buildings: A list of lists of integers
	 * @return: Find the outline of those buildings
	 */
	vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
		auto ans = vector<vector<int>>();
		if (buildings.empty() || buildings[0].empty())  return ans;
		vector<vector<int>> triples; // {pos, height, start or end}
		for (auto &building : buildings) {
			triples.push_back({building[0], building[2], 1});
			triples.push_back({building[1], building[2], 0});
		}
		sort(triples.begin(), triples.end(),
		     [](vector<int> &v1, vector<int> &v2)->int {
			     if (v1[0] != v2[0])
				     return v1[0] < v2[0];
			     else if (v1[2] != v2[2])
				     return v1[2] < v2[2];
			     else
				     return v1[1] < v2[1];
		     });
		multiset<int> maxheap; // use set as hash heap, store height
		int cur_start = 0, cur_end = 0;
		for (auto &triple : triples) {
			if (triple[2]) { // add element
				if (maxheap.empty()) {
					cur_start = triple[0];
				} else if (triple[1] > *maxheap.rbegin() && triple[0] > cur_start) {
					cur_end = triple[0];
					ans.push_back({cur_start, cur_end, *maxheap.rbegin()});
					cur_start = triple[0];
				}
				maxheap.insert(triple[1]);
			} else { // delete element
				int prev_max = *maxheap.rbegin();
				maxheap.erase(maxheap.lower_bound(triple[1]));
				if (maxheap.empty()) {
					cur_end = triple[0];
					ans.push_back({cur_start, cur_end, prev_max});
				} else if (*maxheap.rbegin() < prev_max) {
					cur_end = triple[0];
					ans.push_back({cur_start, cur_end, prev_max});
					cur_start = triple[0];
				}
			}
		}
		return ans;
	}
};