//
// Created by Guanqi Yu on 12/21/17.
//
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

 public:
	/**
	 * non-recursive one
	 */
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> st;
		TreeNode *current = root;
		while (current != nullptr || !st.empty()) {
			// if right node exist, push all pf its left nodes
			while (current != nullptr) {
				st.push(current);
				current = current->left;
			}
			current = st.top();
			st.pop();
			result.push_back(current->val);
			current = current->right;
		}
		return result;
	}

	/**
	 * Non-recursive two
	 */
     vector<int> inorderTraversal2(TreeNode* root) {
         vector<int> result;
         findLeft(root);
         while(!st.empty()) {
             TreeNode *top = st.top();
             st.pop();
             result.push_back(top->val);
             if (top->right != nullptr) {
                 findLeft(top->right);
             }
         }
         return result;
     }

     void findLeft(TreeNode *root) {
         TreeNode *p = root;
         while (p != nullptr) {
             st.push(p);
             p = p->left;
         }
     }

 private:
     stack<TreeNode*> st;

};