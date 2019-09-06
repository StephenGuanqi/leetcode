//
// Created by Guanqi Yu on 3/19/18.
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)    return nullptr;
		if (root->val > key)
			root->left = deleteNode(root->left, key);
		else if (root->val < key)
			root->right = deleteNode(root->right, key);
		else {
			// two null or one null
			if (root->left == nullptr) {
				TreeNode *right = root->right;
				delete root;
				return right;
			} else if (root->right == nullptr) {
				TreeNode *left = root->left;
				delete root;
				return left;
			} else {
				TreeNode *minNode = findMin(root->right);
				int val = root->val;
				swap(root->val, minNode->val);
				root->right = deleteNode(root->right, val);
			}
		}
		return root;
	}

private:
	TreeNode *findMin(TreeNode *root) {
		while (root->left != nullptr)
			root = root->left;
		return root;
	}
};