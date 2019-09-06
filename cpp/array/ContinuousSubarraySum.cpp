//
// Created by Guanqi Yu on 3/21/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
	/*
	 * @param A: An integer array
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> continuousSubarraySum(vector<int> &A) {
		// write your code here
		int minSum = 0;
		int maxSum = INT_MIN, sum = 0;
		int index1 = 0, index2 = -1;
		vector<int> ans(2);
		for (int i = 0; i < A.size(); ++i) {
			sum += A[i];
			if (sum - minSum > maxSum) {
				maxSum = sum - minSum;
				index1 = i;
				ans[0] = index2 + 1;
				ans[1] = index1;
			}
			if (minSum > sum) {
				minSum = sum;
				index2 = i;
			}
		}
		return ans;
	}
};