//
// Created by Guanqi Yu on 12/19/17.
//

/**
 *
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:

	void inorderTraversal(TreeNode *node, int &val, int &min_diff) {
		if (node->left != nullptr) inorderTraversal(node->left, val, min_diff);
		// calc diff for non-leaves nodes, otherwise min_diff is 0
		if (val >= 0) min_diff = min(min_diff, node->val - val);
		val = node->val;
		if (node->right != nullptr) inorderTraversal(node->right, val, min_diff);
	}

	int getMinimumDifference(TreeNode* root) {
		auto min_diff = INT_MAX, val = -1;
		inorderTraversal(root, val, min_diff);
		return min_diff;
	}
};