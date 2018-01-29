//
// Created by Guanqi Yu on 1/9/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class NestedInteger {
public:
	bool isInteger() const;
	int getInteger() const;
	const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		int sz = nestedList.size();
		for (int i = sz - 1; i >= 0; --i) {
			st.push(nestedList[i]);
		}
	}

	// @return {int} the next element in the iteration
	int next() {
		int ans = st.top().getInteger();
		st.pop();
		return ans;
	}

	// @return {boolean} true if the iteration has more element or false
	bool hasNext() {
		while (!st.empty()) {
			if (st.top().isInteger())
				return true;
			auto nlist = st.top().getList();
			st.pop();
			for (int i = nlist.size() - 1; i >= 0; --i)
				st.push(nlist[i]);
		}
		return false;
	}

private:
	stack<NestedInteger> st;

};