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
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())   return nullptr;
		if (nums.size() == 1)   return new TreeNode(nums[0]);
		int mid = nums.size() / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		vector<int> leftHalf(nums.begin(), nums.begin() + mid);
		vector<int> rightHalf(nums.begin() + mid + 1, nums.end());

		root->left = sortedArrayToBST(leftHalf);
		root->right = sortedArrayToBST(rightHalf);
		return root;
	}
};