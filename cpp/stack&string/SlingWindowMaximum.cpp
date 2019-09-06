//
// Created by Guanqi Yu on 2/14/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	/*
	 * @param nums: A list of integers
	 * @param k: An integer
	 * @return: The maximum number inside the window at each moving
	 */
	vector<int> maxSlidingWindow(vector<int> nums, int k) {
		vector<int> ans;
		if (nums.empty() || k > nums.size())   return ans;
		deque<int> dq;
		for (int i = 0; i < k - 1; ++i) {
			enqueue(dq, nums[i]);
		}
		for (int i = k - 1; i < nums.size(); ++i) {
			enqueue(dq, nums[i]);
			ans.push_back(dq.front());
			outqueue(dq, nums[i - k + 1]);
		}
		return ans;
	}

private:
	void enqueue(deque<int> &dq, int num) {
		while (!dq.empty() && num > dq.back()) {
			dq.pop_back();
		}
		dq.push_back(num);
	}

	void outqueue(deque<int> &dq, int num) {
		if (num == dq.front()) {
			dq.pop_front();
		}
	}
};