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

class Solution {
    // top down O(N^2)
public:
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;

        int left=depth(root->left);
        int right=depth(root->right);

        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }



// public:
//     bool isBalanced(TreeNode* root) {
//         return checkBalanced(root).first;
//     }

// private:
//     pair<bool, int> checkBalanced(TreeNode *root) {
//         if (root == nullptr)    return make_pair(true, 0);
//         pair<bool, int> left_result = checkBalanced(root->left);
//         pair<bool, int> right_result = checkBalanced(root->right);
//         // check balanced
//         if (!left_result.first || !right_result.first)
//             return make_pair(false, -1);
//         // check height
//         if (abs(left_result.second - right_result.second) > 1)
//             return make_pair(false, -1);
//         return make_pair(true, max(left_result.second, right_result.second) + 1);
//     }

};