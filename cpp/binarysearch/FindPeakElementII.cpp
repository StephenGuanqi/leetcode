//
// Created by Guanqi Yu on 2/12/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
	/**
	 * wrong
	 */
public:
	/*
	 * @param A: An integer matrix
	 * @return: The index of the peak
	 */
	vector<int> findPeakII(vector<vector<int>> &A) {
		vector<int> ans;
		if (A.empty() || A[0].empty())  return ans;
		int m = A.size(), n = A[0].size();
		int r1 = 0, r2 = m - 1, c1 = 0, c2 = n - 1;
		while (r1 < r2 && c1 < c2) {
			// binary search on rows
			int midr = r1 + (r2 - r1) / 2;
			auto maxcit = max_element(A[midr].begin() + c1, A[midr].begin() + c2 + 1);
			int pos = maxcit - A[midr].begin();
			if (A[midr - 1][pos] > *maxcit) {
				r2 = midr - 1;
			} else if (A[midr + 1][pos] > *maxcit) {
				r1 = midr + 1;
			} else {
				// find answer
				ans.push_back(midr);
				ans.push_back(pos);
				return ans;
			}
			// binary search on columns
			int midc = c1 + (c2 - c1) / 2;
			auto maxrit = max_element(A.begin() + r1, A.begin() + r2 + 1,
			                          [midc](vector<int> &row1, vector<int> &row2) {
				                          return row1[midc] < row2[midc];
			                          });
			pos = maxrit - A.begin();
			if (A[pos][midc + 1] > (*maxrit)[midc]) {
				c1 = midc + 1;
			} else if (A[pos][midc - 1] > (*maxrit)[midc]) {
				c2 = midc - 1;
			} else {
				ans.push_back(pos);
				ans.push_back(midc);
				return ans;
			}
		}
		ans.push_back(r1);
		ans.push_back(c1);
		return ans;
	}


};

//int main() {
//	vector<vector<int>> A = {{0, 0, 0, 0, 0, 0},
//	                         {0, 1, 12, 3, 4, 0},
//	                         {0, 5, 11, 7, 12, 0},
//	                         {0, 9, 10, 9, 13, 0},
//	                         {0, 13, 9, 15, 16, 0},
//	                         {0, 0, 0, 0, 0, 0}};
//	Solution().findPeakII(A);
//}