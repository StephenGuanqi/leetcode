//
// Created by Guanqi Yu on 2/10/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;


class MyQueue {
public:
	MyQueue() {
		// do intialization if necessary
	}

	/*
	 * @param element: An integer
	 * @return: nothing
	 */
	void push(int element) {
		st1.push(element);
	}

	/*
	 * @return: An integer
	 */
	int pop() {
		adjust();
		int tmp = st2.top();
		st2.pop();
		return tmp;
	}

	/*
	 * @return: An integer
	 */
	int top() {
		adjust();
		return st2.top();
	}

	void adjust() {
		if (!st2.empty())
			return;
		while (!st1.empty()) {
			st2.push(st1.top());
			st1.pop();
		}
	}

private:

	stack<int> st1;
	stack<int> st2;
};