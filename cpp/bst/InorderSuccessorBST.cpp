//
// Created by Guanqi Yu on 1/29/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		// has right subtree
		if (p->right != nullptr)
			return findMin(p->right);
		// right node is null
		auto res = getParents(root, p);
		if (!res.first) return nullptr;
		// can find a path
		auto parents = res.second;
		TreeNode *current = p;
		while (!parents.empty() && parents.top()->right == current) {
			current = parents.top();
			parents.pop();
		}
		// input stack is empty ---> p is root and p don't have right child
		// or p is on the right heavy subtree of the root
		if (parents.empty())    return nullptr;
		return parents.top();
	}

private:
	TreeNode* findMin(TreeNode *root) {
		while (root->left != nullptr)
			root = root->left;
		return root;
	}

	pair<bool, stack<TreeNode*>> getParents(TreeNode *root, TreeNode *p) {
		stack<TreeNode*> st;
		while (root != nullptr && root != p) {
			st.push(root);
			root = root->val < p->val ? root->right : root->left;
		}
		if (root != p)
			return {false, stack<TreeNode*>()};
		return {true, st};
	}
};


class Solution2 {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == nullptr)
			return nullptr;
		if (root->val <= p->val)
			return inorderSuccessor(root->right, p);
		else {
			TreeNode *left = inorderSuccessor(root->left, p);
			return left == nullptr ? root : left;
		}
	}

};