//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class ZigzagIterator2 {
public:
	/*
	* @param vecs: a list of 1d vectors
	*/ZigzagIterator2(vector<vector<int>>& vecs) {
		for (auto &vec : vecs) {
			if (vec.empty())    continue;
			q.push({vec.begin(), vec.end()});
		}
	}

	/*
	 * @return: An integer
	 */
	int next() {
		auto itp = q.front(); q.pop(); // copy here
		int result = *itp.first;
		++itp.first;
		if (itp.first != itp.second)
			q.push(itp);
		return result;
	}

	/*
	 * @return: True if has next
	 */
	bool hasNext() {
		return !q.empty();
	}
private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};
