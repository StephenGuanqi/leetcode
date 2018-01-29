//
// Created by Guanqi Yu on 1/9/18.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class Vector2D {
public:
	Vector2D(vector<vector<int>>& vec2d) {
		for (auto &vec : vec2d) {
			if (vec.empty())    continue;
			q.push({vec.begin(), vec.end()});
		}
	}

	int next() {
		auto &itp = q.front(); // shouldn't be copy here
		int result = *itp.first;
		++itp.first;
		if (itp.first == itp.second)
			q.pop();
		return result;
	}

	bool hasNext() {
		return !q.empty();
	}

private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};