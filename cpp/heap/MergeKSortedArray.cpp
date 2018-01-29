//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	/*
	 * @param arrays: k sorted integer arrays
	 * @return: a sorted array
	 */
	struct itpair {
		vector<int>::iterator beg;
		vector<int>::iterator end;
		itpair(vector<int>::iterator b, vector<int>::iterator e)
				: beg(b), end(e) {}
	};

	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
		vector<int>::iterator b1 = arrays[0].begin();
		vector<int>::iterator e1 = arrays[0].end();
		vector<int>::iterator b2 = arrays[1].begin();
		vector<int>::iterator e2 = arrays[1].end();
		auto cmp = [](itpair &p1, itpair &p2) {
			return *(p1.beg) > *(p2.beg);
		};
		priority_queue<itpair, vector<itpair>, decltype(cmp)> q(cmp);
		for (auto &vec : arrays) {
			if (vec.empty())    continue;
			q.push({vec.begin(), vec.end()});
		}
		vector<int> ans;
		while (!q.empty()) {
			auto itp = q.top(); q.pop();
			ans.push_back(*itp.beg);
			if (itp.beg + 1 != itp.end)
				q.push({itp.beg + 1, itp.end});
		}
		return ans;
	}
};

//int main() {
//	vector<vector<int>> vecs = {{1,3,5,7}, {2,4,6}, {0,8,9,10,11}};
//	Solution().mergekSortedArrays(vecs);
//}