//
// Created by Guanqi Yu on 12/24/17.
//
/*
 * BST characteristics: in-order traversal is a non-descending sequence
 * definition: all left node must be less than or equal to current node
 *
 * Maximum, minimum -----> da lei tai
 * BST  -----> traversal(in-order, parameter), divide and conquer, non-recursive
 *
 * divide and conquer: result type
 * traversal: parameter, in-order, pre-order   (daleitai or na ben ji)
 *
 * And also think about the data augmentation
 *
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

/**
 *
 * Traverse Order:   traverse vs divide conquer vs non-recursive
 * divide conquer  ---->   check the meaning of the subroutine
 * traversal, parameter has the return result
 */
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	// traverse
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* prev = NULL;
		return validate(root, prev);
	}

	bool validate(TreeNode *node, TreeNode *&prev) { // notice the reference here
		if (node == NULL) return true;
		if (!validate(node->left, prev)) return false;
		if (prev != NULL && prev->val >= node->val) return false;
		prev = node;
		return validate(node->right, prev);
	}

};

class Solution2 {
	// divide and conquer
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, nullptr, nullptr); // root node has no min and max limit
	}

	/**
	* BST definition, all left nodes less than current node, all right greater than current node
	* Passing down min and max value
	* Subroutine definition: is the current root and its subtree range between minNode and maxNode
	*/
	bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
		if (root == nullptr)    return true;
		if (minNode != nullptr && minNode->val >= root->val ||
		    maxNode != nullptr && maxNode->val <= root->val)
			return false;
		return isValidBST(root->left, minNode, root) &&
		       isValidBST(root->right, root, maxNode);
	}

};

class Solution3 {
	// non-recursive
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode *current = root;
		TreeNode *lastNode = nullptr;
		while (current != nullptr || !st.empty()) {
			while (current != nullptr) {
				st.push(current);
				current = current->left;
			}
			current = st.top();
			st.pop();
			if (lastNode != nullptr && lastNode->val >= current->val)
				return false;
			lastNode = current;
			current = current->right;
		}
		return true;
	}

};