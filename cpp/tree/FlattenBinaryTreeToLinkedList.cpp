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
class Solution2 {

 public:
     void flatten(TreeNode* root) {
         helper(root);
     }

 private:
     //flatten the subtree root at root and return the last node
     TreeNode *helper(TreeNode *root) {
         if (root == nullptr) return nullptr;
         TreeNode *leftLast = helper(root->left);
         TreeNode *rightLast = helper(root->right);
         // think about situation of one null and both null
         if (leftLast != nullptr) {
             leftLast->right = root->right;
             root->right = root->left;
             root->left = nullptr;
         }
         if (rightLast != nullptr)
             return rightLast;
         if (leftLast != nullptr)
             return leftLast;
         return root;
     }

};

class Solution1 {

public:
	// preorder traversal
	void flatten(TreeNode *root) {
		if (root == nullptr)    return;
		if (lastNode != nullptr) {
			lastNode->right = root;
			lastNode->left = nullptr;
		}
		lastNode = root;
		/**
		 * seriously!!! root->right is changed!!
		 */
		TreeNode *right = root->right;
		flatten(root->left);
		flatten(right);
	}

private:
	TreeNode *lastNode;
};

class Solution3 {

public:
	// preorder traversal
	void flatten(TreeNode *root) {
		if (root == nullptr) return;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode *node = st.top();
			st.pop();
			if (node->right != nullptr)  st.push(node->right);
			if (node->left != nullptr)   st.push(node->left);
			// flatten
			node->left = nullptr;
			if (st.empty()) // check stack's empry on the last element in stack (right most on tree)
				node->right = nullptr;
			else
				node->right = st.top();
		}
	}
};

//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//TreeNode* stringToTreeNode(string input) {
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    if (!input.size()) {
//        return nullptr;
//    }
//
//    string item;
//    stringstream ss;
//    ss.str(input);
//
//    getline(ss, item, ',');
//    TreeNode* root = new TreeNode(stoi(item));
//    queue<TreeNode*> nodeQueue;
//    nodeQueue.push(root);
//
//    while (true) {
//        TreeNode* node = nodeQueue.front();
//        nodeQueue.pop();
//
//        if (!getline(ss, item, ',')) {
//            break;
//        }
//
//        trimLeftTrailingSpaces(item);
//        if (item != "null") {
//            int leftNumber = stoi(item);
//            node->left = new TreeNode(leftNumber);
//            nodeQueue.push(node->left);
//        }
//
//        if (!getline(ss, item, ',')) {
//            break;
//        }
//
//        trimLeftTrailingSpaces(item);
//        if (item != "null") {
//            int rightNumber = stoi(item);
//            node->right = new TreeNode(rightNumber);
//            nodeQueue.push(node->right);
//        }
//    }
//    return root;
//}
//
//string treeNodeToString(TreeNode* root) {
//    if (root == nullptr) {
//        return "[]";
//    }
//
//    string output = "";
//    queue<TreeNode*> q;
//    q.push(root);
//    while(!q.empty()) {
//        TreeNode* node = q.front();
//        q.pop();
//
//        if (node == nullptr) {
//            output += "null, ";
//            continue;
//        }
//
//        output += to_string(node->val) + ", ";
//        q.push(node->left);
//        q.push(node->right);
//    }
//    return "[" + output.substr(0, output.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        Solution1().flatten(root);
//
//        string out = treeNodeToString(root);
//        cout << out << endl;
//    }
//    return 0;
//}
