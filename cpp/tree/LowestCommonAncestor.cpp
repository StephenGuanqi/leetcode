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
	if node data structure can be augmented, 7->2->5->3 . 4->2->5->3 .  2
	All binary tree problem, think about divide and conquer
	left subtree solve the problem, then right subtree solve the problem
	list all possible position and corresponding result for p and q
	* return result type can be combined when it has boolean field
	* this question is similar to check balanced ---> return -1 and return pair<bool, int>
	* return ancestor or p(if exist) or q(if exist)
	*/
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!nodeExistInSubtree(root, q) || !nodeExistInSubtree(root, p))   return nullptr;
		return helper(root, p, q);
	}

	TreeNode* helper(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root == nullptr || root == p || root == q)    return root;

		bool pIsOnLeft = nodeExistInSubtree(root->left, p);
		bool qIsOnLeft = nodeExistInSubtree(root->left, q);
		if (pIsOnLeft != qIsOnLeft)
			return root;
		TreeNode *childNode = pIsOnLeft ? root->left : root->right;
		return lowestCommonAncestor(childNode, p, q);
		/**
		 * needs check for A B both or one of them doesn't exist in the tree
		 */
	}

	bool nodeExistInSubtree(TreeNode *root, TreeNode *node) {
		if (root == nullptr)    return false;
		if (root == node)    return true;
		return nodeExistInSubtree(root->left, node) ||
		       nodeExistInSubtree(root->right, node);
	}

};

class Solution2 {

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!nodeExistInSubtree(root, q) || !nodeExistInSubtree(root, p))   return nullptr;
		return helper(root, p, q);
	}

	TreeNode* helper(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root == nullptr || root == p || root == q)    return root;
/**
 * seriously wrong here, because we don't know which side p and q is
 * could be p is on right and q on left but both return false
 */
//		 bool isLeft = nodeExistInSubtree(root->left, p);
//		 bool isRight = nodeExistInSubtree(root->right, q);
//		 if (isLeft != isRight)
//		     return isLeft ? lowestCommonAncestor(root->left, p, q) :
//		                     lowestCommonAncestor(root->right, p, q);
//		 if (isLeft)
//		     return root;
//		 return nullptr;
		bool isLeft = nodeExistInSubtree(root->left, p);
		bool isRight = nodeExistInSubtree(root->right, q);
		if (isLeft != isRight)
			return isLeft ? helper(root->left, p, q) :
			       helper(root->right, p, q);
		return root;
	}

	bool nodeExistInSubtree(TreeNode *root, TreeNode *node) {
		if (root == nullptr)    return false;
		if (root == node)    return true;
		return nodeExistInSubtree(root->left, node) ||
		       nodeExistInSubtree(root->right, node);
	}

};


class Solution3 {
	/**
	 * doesn't work when one of the p or q doesn't exist in tree
	 */
public:
	// subroutine definition!!!
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)    return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr && right == nullptr)    return nullptr;
		if (left != nullptr && right != nullptr)    return root;
		return left ? left : right;
	}

};

class Solution4 {
	struct ResultType {
		bool a_exist, b_exist;
		TreeNode *node;
		ResultType(bool _a_exist, bool _b_exist, TreeNode *_node):
				a_exist(_a_exist), b_exist(_b_exist), node(_node) {}
	};
public:
	/*
	 * @param root: The root of the binary tree.
	 * @param A: A TreeNode
	 * @param B: A TreeNode
	 * @return: Return the LCA of the two nodes.
	 */
	TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
		ResultType result = helper(root, A, B);
		if (!result.a_exist || !result.b_exist)
			return nullptr;
		return result.node;
	}

private:
	ResultType helper(TreeNode *root, TreeNode *A, TreeNode *B) {
		if (root == nullptr)    return ResultType(false, false, nullptr);
		ResultType left_rs = helper(root->left, A, B);
		ResultType right_rs = helper(root->right, A, B);
		bool a_exist = left_rs.a_exist || right_rs.a_exist || root == A;
		bool b_exist = left_rs.b_exist || right_rs.b_exist || root == B;
		if (root == A || root == B)    return ResultType(a_exist, b_exist, root);
		if (left_rs.node != nullptr && right_rs.node != nullptr)
			return ResultType(a_exist, b_exist, root);
		if (left_rs.node != nullptr)
			return ResultType(a_exist, b_exist, left_rs.node);
		if (right_rs.node != nullptr)
			return ResultType(a_exist, b_exist, right_rs.node);
		return ResultType(a_exist, b_exist, nullptr);
	}


};


//void trimLeftTrailingSpaces(string &input) {
//	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//		return !isspace(ch);
//	}));
//}
//
//void trimRightTrailingSpaces(string &input) {
//	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//		return !isspace(ch);
//	}).base(), input.end());
//}
//
//TreeNode* stringToTreeNode(string input) {
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);
//	if (!input.size()) {
//		return nullptr;
//	}
//
//	string item;
//	stringstream ss;
//	ss.str(input);
//
//	getline(ss, item, ',');
//	TreeNode* root = new TreeNode(stoi(item));
//	queue<TreeNode*> nodeQueue;
//	nodeQueue.push(root);
//
//	while (true) {
//		TreeNode* node = nodeQueue.front();
//		nodeQueue.pop();
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int leftNumber = stoi(item);
//			node->left = new TreeNode(leftNumber);
//			nodeQueue.push(node->left);
//		}
//
//		if (!getline(ss, item, ',')) {
//			break;
//		}
//
//		trimLeftTrailingSpaces(item);
//		if (item != "null") {
//			int rightNumber = stoi(item);
//			node->right = new TreeNode(rightNumber);
//			nodeQueue.push(node->right);
//		}
//	}
//	return root;
//}
//
//int stringToInteger(string input) {
//	return stoi(input);
//}
//
//string treeNodeToString(TreeNode* root) {
//	if (root == nullptr) {
//		return "[]";
//	}
//
//	string output = "";
//	queue<TreeNode*> q;
//	q.push(root);
//	while(!q.empty()) {
//		TreeNode* node = q.front();
//		q.pop();
//
//		if (node == nullptr) {
//			output += "null, ";
//			continue;
//		}
//
//		output += to_string(node->val) + ", ";
//		q.push(node->left);
//		q.push(node->right);
//	}
//	return "[" + output.substr(0, output.length() - 2) + "]";
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		TreeNode* root = stringToTreeNode(line);
//		getline(cin, line);
//		int m = stringToInteger(line);
//		getline(cin, line);
//		int n = stringToInteger(line);
//
//		TreeNode* ret = Solution().lowestCommonAncestor(root, new TreeNode(m), new TreeNode(n));
//
//		string out = treeNodeToString(ret);
//		cout << out << endl;
//	}
//	return 0;
//}