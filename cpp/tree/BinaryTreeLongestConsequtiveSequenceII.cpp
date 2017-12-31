//
// Created by Guanqi Yu on 12/26/17.
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
	/**
	 * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

	 Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid,
	 but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
	 */
/**
 * Like LCA, think about what is the object you want, and solve according to multiple situations
 */
public:
	int longestConsecutive(TreeNode* root) {
		helper(root);
		return longest;
	}
	// longest consecutive path start from the node root
	pair<int, int> helper(TreeNode *root) {
		if (root == nullptr)    return make_pair(0, 0);
		auto leftRst = helper(root->left);
		auto rightRst = helper(root->right);
		int down = 0, up = 0;
		if (root->left != nullptr && root->left->val + 1 == root->val)
			down = max(down, leftRst.first + 1);
		if (root->right != nullptr && root->right->val + 1 == root->val)
			down = max(down, rightRst.first + 1);
		if (root->left != nullptr && root->left->val - 1 == root->val)
			up = max(up, leftRst.second + 1);
		if (root->right != nullptr && root->right->val - 1 == root->val)
			up = max(up, rightRst.second + 1);
		int length = down + 1 + up;
		longest = max(longest, length);
		return make_pair(down, up);
	}

private:
	int longest = 0;
};