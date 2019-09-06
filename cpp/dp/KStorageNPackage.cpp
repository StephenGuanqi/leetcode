//
// Created by Guanqi Yu on 2/24/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

//class Solution {
//public:
//	vector<double> getKCoordinates(vector<int> &coordinates, int K) {
//		vector<double> ans;
//		if (coordinates.empty() || K == 0)    return ans;
//		int n = coordinates.size();
//		if ( K >= n) {
//			auto ans(coordinates.begin(), coordinates.end());
//			return ans;
//		}
//
//		vector<vector<double>> f(n, vector<double>(K, INT_MAX)); // minimum distance
//		vector<vector<pair<double, int>>> prev(n, vector<pair<double, int>>(K)); // {prev centroid coordinate, prev index}
//		// init
//		for (int i = 0; i < n; ++i) {
//			auto p = calcMinDist(coordinates, 0, i);
//			f[i][0] = p.first;
//			prev[i][0] = {p.second, 0};
//		}
//
//		// dp
//		for (int k = 1; k < K; ++k) {
//			f[0][k] = 0;
//			prev[0][k] = {coordinates[0], 0};
//			for (int i = 1; i < n; ++i) {
//				// update the F[i][k] and get the prev
//				for (int j = 0; j < i; ++j) {
//					auto p = calcMinDist(coordinates, j + 1, i);
//					double val = f[j][k - 1] + p.first;
//					if (val < f[i][k]) {
//						f[i][k] = val;
//						prev[i][k] = {p.first, j};
//					}
//				}
//			}
//		};
//
//		// solution
//		int j = n - 1;
//		for (int i = K - 1; i >= 0 ; --i) {
//			ans.push_back(prev[j][i].first);
//			j = prev[j][i].second;
//		}
//		return ans;
//	};
//
//private:
//	// minDist, centroid key, value pair
//	pair<double, double> calcMinDist(vector<int> coordinates, int i, int j) {
//		if (i == j) return {0, coordinates[i]};
//		double centroid = accumulate(coordinates.begin() + i, coordinates.begin() + j, 0) / (j - i + 1);
//		double minDist = accumulate(coordinates.begin() + i, coordinates.begin() + j, 0, [centroid](double accum, int v) ->double {
//			return accum + (v - centroid) * (v - centroid);
//		});
//		return {minDist, centroid};
//
//	}
//};