//
// Created by Guanqi Yu on 12/25/17.
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
	 * DFS + daleitai
	 */
public:
	int longestConsecutive(TreeNode* root) {
		dfs(root, nullptr, 1);
		return longest;
	}

	void dfs(TreeNode *root, TreeNode *prev, int length) {
		if (root == nullptr)    return;
		length = (prev != nullptr && prev->val + 1 == root->val) ?
		         length + 1 : 1;
		longest = max(length, longest);
		dfs(root->left, root, length);
		dfs(root->right, root, length);
	}

private:
	int longest = 0;
};

class Solution2 {
	/**
	 * Traverse + Divide & Conquer
	 */
public:
	int longestConsecutive(TreeNode* root) {
		helper(root);
		return longest;
	}
	// max length start with node root
	int helper(TreeNode *root) {
		if (root == nullptr)    return 0;
		int leftLength = helper(root->left);
		int rightLength = helper(root->right);
		int length = 1;
		if (root->left != nullptr && root->left->val == root->val + 1)
			length = max(length, leftLength + 1);
		if (root->right != nullptr && root->right->val == root->val + 1)
			length = max(length, rightLength + 1);
		if (length > longest)
			longest = length;
		return length;
	}

private:
	int longest = 0;
};