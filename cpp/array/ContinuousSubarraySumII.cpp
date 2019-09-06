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
	vector<int> continuousSubarraySumII(vector<int> &A) {
		// write your code here
		// max sum
		int sum = 0;
		int maxSum = INT_MIN, prevMin = 0;
		vector<int> ans1(2);
		int index1 = 0, index2 = -1;
		for (int i = 0; i < A.size(); ++i) {
			sum += A[i];
			if (sum - prevMin > maxSum) {
				maxSum = sum - prevMin;
				index1 = i;
				ans1[0] = index2 + 1;
				ans1[1] = index1;
			}
			if (prevMin > sum) {
				prevMin = sum;
				index2 = i;
			}
		}
		int totalSum = sum;
		cout << ans1[0] << " " << ans1[1] << endl;
		// min sum
		sum = 0;
		int minSum = INT_MAX, prevMax = 0;
		vector<int> ans2(2);
		index1 = 0, index2 = -1;
		for (int i = 0; i < A.size(); ++i) {
			sum += A[i];
			if (sum - prevMax < minSum) {
				minSum = sum - prevMax;
				index1 = i;
				ans2[0] = index2 + 1;
				ans2[1] = index1;
			}
			if (prevMax < sum) {
				prevMax = sum;
				index2 = i;
			}
		}
		cout << ans2[0] << " " << ans2[1] << endl;

		// all negative
		if (totalSum == minSum) {
			return ans1;
		}
		if (maxSum >= totalSum - minSum)
			return ans1;
		vector<int> ans = {ans2[1] + 1, ans2[0] - 1};
		return ans;
	}
};