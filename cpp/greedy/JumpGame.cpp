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
	 * greedy approach
	 * we can jump whatever step at A[i]
	 * as long as max_jump reach the end of the array, return true
	 */
public:
	/*
	 * @param A: A list of integers
	 * @return: A boolean
	 */
	bool canJump(vector<int> &A) {
		// write your code here
		int max_jump = 0;
		for (int i = 0; i < A.size(); ++i) {
			if (max_jump >= A.size() - 1) {
				return true;
			}
			if (i > max_jump)
				break;
			max_jump = max(A[i] + i, max_jump);
		}
		return false;
	}
};