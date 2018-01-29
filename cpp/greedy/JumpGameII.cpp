//
// Created by Guanqi Yu on 1/27/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
	/**
	 * assume always reach the end, therefore low always equals to prehigh + 1
	 * */
public:
	/*
	 * @param A: A list of integers
	 * @return: An integer
	 */
	int jump(vector<int> &A) {
		int step = 0;
		int low = 0, high = 0, prehigh = 0; // each level order traversal's range in bfs
		while (high < A.size() - 1) {
			++step;
			for (int i = low; i <= prehigh; ++i) {
				high = max(high, A[i] + i);
			}
			low = prehigh + 1;
			prehigh = high;
		}
		return step;
	}
};