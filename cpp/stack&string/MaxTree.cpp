//
// Created by Guanqi Yu on 2/11/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	/*
	 * @param A: Given an integer array with no duplicates.
	 * @return: The root of max tree.
	 */
	// for each element, find first element on its left&right that is greater than it
	// use the smaller one
	TreeNode * maxTree(vector<int> &A) {
		if (A.empty())  return nullptr;
		// monocular decreasing stack
		stack<TreeNode*> st;
		st.push(new TreeNode(INT_MAX));
		int num = 0;
		TreeNode *res = nullptr;
		for (int i = 0; i <= A.size(); ++i) {
			// add dummy Max at final step to pop up all elements
			if (i == A.size()) {
				num = INT_MAX;
			} else {
				num = A[i];
			}

			if (st.top()->val > num) {
				st.push(new TreeNode(num));
			} else {
				TreeNode *newnode = new TreeNode(num);
				while (st.top()->val < num) {
					// get last node with the biggest val
					if (st.size() == 2)
						res = st.top();
					auto cur_top = st.top();
					st.pop();
					if (st.top()->val > num) {
						// attach cur to the new added's left
						newnode->left = cur_top;
					} else {
						// attach cur to previous's right
						st.top()->right = cur_top;
					}
				}
				st.push(newnode);
			}
		}
		// release memory
		delete st.top();
		st.pop();
		delete st.top();

		return res;
	}
};