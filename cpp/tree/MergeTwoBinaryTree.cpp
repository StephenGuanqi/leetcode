//
// Created by Guanqi Yu on 12/21/17.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
		/**
		* not in-place operation, but recursive
		* Serious problem!! can't return address of stack variable!!!
		*/
		if (t1 && t2) {
			TreeNode *root = new TreeNode(t1->val + t2->val);
			root->left = mergeTrees(t1->left, t2->left);
			root->right = mergeTrees(t1->right, t2->right);
			return root;
		} else {
			return t1 ? t1 : t2;
		}
	}
};