//
// Created by Guanqi Yu on 1/8/18.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
	/*
	* @param k: An integer
	*/Solution(int k) {
		capacity = k;
	}

	/*
	 * @param num: Number to be added
	 * @return: nothing
	 */
	void add(int num) {
		if (q.size() < capacity) {
			q.push(num);
			return;
		}
		if (q.top() < num) {
			q.pop();
			q.push(num);
		}
		return;
	}

	/*
	 * @return: Top k element
	 */
	vector<int> topk() {
		vector<int> ans;
		int n = q.size();
		for (int i = 0; i < n; ++i) {
			ans.push_back(q.top());
			q.pop();
		}
		for (int num : ans) {
			q.push(num);
		}
		sort(ans.begin(), ans.end(),  std::greater<int>());
		return ans;
	}

private:
	priority_queue<int, vector<int>, greater<int>> q;
	int capacity;
};



class Solution2 {
	/**
	 * add operation amortized O(1) before it is full, not like priority queue
	 */
public:
	/*
	* @param k: An integer
	*/Solution2(int k) {
		capacity = k;
	}

	/*
	 * @param num: Number to be added
	 * @return: nothing
	 */
	void add(int num) {
		if (queue.size() < capacity) {
			queue.push_back(num);
			return;
		}
		// full
		if (!isHeap) {
			make_heap(queue.begin(), queue.end(), cmp);
			isHeap = true;
		}
		if (queue.front() < num) {
			// pop front
			pop_heap(queue.begin(), queue.end(), cmp); queue.pop_back();
			// push back
			queue.push_back(num); push_heap(queue.begin(), queue.end(), cmp);
		}
	}

	/*
	 * @return: Top k element
	 */
	vector<int> topk() {
		vector<int> vec(queue.begin(), queue.end());
		sort(vec.begin(), vec.end(), cmp);
		return vec;
	}

private:
	static bool cmp(int a, int b) {
		return a > b;
	}
	vector<int> queue;
	bool isHeap = false;
	int capacity;
};