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

class Solution1 {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode *current = root;
		while (current != nullptr || !st.empty()) {
			while (current != nullptr) {
				st.push(current);
				current = current->left;
			}
			current = st.top(); st.pop();
			if (--k == 0) break;
			current = current->right;
		}
		return current->val;
	}
};

class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int left_amount = count(root->left);
		if (k <= left_amount)
			return kthSmallest(root->left, k);
		else if (k > left_amount + 1)
			return kthSmallest(root->right, k - left_amount - 1);
		return root->val;
	}

private:
	// tree augmentation
	int count(TreeNode *node) {
		if (node == nullptr)    return 0;
		return 1 + count(node->left) + count(node->right);
	}
};