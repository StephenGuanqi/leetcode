//
// Created by Guanqi Yu on 1/31/18.
//


#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;

	Point() : x(0), y(0) {}

	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	/*
	 * @param n: An integer
	 * @param m: An integer
	 * @param operators: an array of point
	 * @return: an integer array
	 */
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		vector<int> ans;
		if (operators.empty()) return ans;
		// initialize
		cnt = 0;
		for (int i = 0; i < n * m; ++i)
			parent_.push_back(i);
		size_.assign(n * m, 1);
		// union find
		vector<vector<int>> island(n, vector<int>(m));
		for (auto &p : operators) {
			if (island[p.x][p.y]) {
				ans.push_back(cnt);
				continue;
			}
			++cnt;
			island[p.x][p.y] = 1;
			for (int j = 0; j < 4; ++j) {
				int newx = p.x + diff[j][0];
				int newy = p.y + diff[j][1];
				if (newx >= 0 && newx < n && newy >= 0 && newy < m
				    && island[newx][newy]) {
					Point newp = {newx, newy};
					connect(p, newp, m);
				}
			}
			ans.push_back(cnt);
		}
		return ans;
	}

private:
	void connect(Point &p1, Point &p2, int m) {
		int root1 = find(id(p1, m));
		int root2 = find(id(p2, m));
		if (root1 == root2) return;
		if (size_[root1] > size_[root2]) {
			parent_[root2] = root1;
			size_[root1] += size_[root2];
		} else {
			parent_[root1] = root2;
			size_[root2] += size_[root1];
		}
		--cnt;
	}

	int id(Point &p, int m) {
		return p.x * m + p.y;
	}

	int find(int x) {
		if (x != parent_[x])
			parent_[x] = find(parent_[x]);
		return parent_[x];
	}

	vector<int> parent_;
	vector<int> size_;
	int cnt; // # of sea
	const int diff[4][2] = {{1,  0},
	                        {0,  1},
	                        {-1, 0},
	                        {0,  -1}};
};