//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	/*
	 * @param points: a list of points
	 * @param origin: a point
	 * @param k: An integer
	 * @return: the k closest points
	 */
	vector<Point> kClosest(vector<Point> points, Point origin, int k) {
		// max heap compare function
		auto cmp = [&](const Point &p1, const Point &p2) {
			long long dist1 = calcDist(p1, origin);
			long long dist2 = calcDist(p1, origin);
			// return dist1 != dist2 ? dist1 < dist2 :
			//       (p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y);
			if (dist1 != dist2) return dist1 < dist2;
			else if (p1.x != p2.x) return p1.x < p2.x;
			else return p1.y < p2.y;
		};
		priority_queue<Point, vector<Point>, decltype(cmp)> q(cmp);
		for (auto point : points) {
			if (q.size() < k)
				q.push(point);
			else if (!cmp(q.top(), point)) {
				q.pop();
				q.push(point);
			}
		}
		vector<Point> ans;
		for (int i = 0; i < k; ++i) {
			ans.push_back(q.top());
			q.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

private:
	long long calcDist(const Point &p1, const Point &p2) {
		double difx = p1.x - p2.x;
		double dify = p1.y - p2.y;
		long long dist = 0;
		dist = pow(difx, 2) + pow(dify, 2);
		dist = sqrt(dist);
		return dist;
	}

};