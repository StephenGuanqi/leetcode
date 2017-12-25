//
// Created by Guanqi Yu on 12/24/17.
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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == nullptr) return result;
		st.push(root);
		while(!st.empty()) {
			TreeNode *top = st.top();
			result.push_back(top->val);
			st.pop();
			if (top->right != nullptr) st.push(top->right);
			if (top->left != nullptr) st.push(top->left);
		}
		return result;
	}
};