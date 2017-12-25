//
// Created by Guanqi Yu on 12/19/17.
//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	// int maxDepth(TreeNode* root)
	//{
	//     return root == nullptr? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
	// }

	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		int res = 0;
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty())
		{
			++res;
			for(int i = 0, n = q.size(); i < n; ++i)
			{
				TreeNode *p = q.front();
				q.pop();

				if(p->left != nullptr)
					q.push(p->left);
				if(p->right != nullptr)
					q.push(p->right);
			}
		}
		return res;
	}

};