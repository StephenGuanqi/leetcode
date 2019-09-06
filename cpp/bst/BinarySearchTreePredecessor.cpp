//
// Created by Guanqi Yu on 3/23/18.
//

#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

#include <iostream>
using namespace std;

/*
           5
        3     8
            7   13
              12
            11   12.5

     13
   7
 6
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getLargest(TreeNode *root) {
	while (root->right != nullptr) {
		root = root->right;
	}
	return root->val;
}

// Pass 1 - 5 13
// pass 2 - right = 8 13   null return 8
// pass 3 - 13 13  null
// pass 4 - null


// Pass 1 - 13 13   return null


// Pass1 - 5 13 right 12.5
// Pass2 - 8 13 right 12.5  return right
// Pass3 - 13 13 right = 12.5 return right
// Pass4 - getL 12  return 12.5
TreeNode *predecessor(TreeNode *root, int val) {
	if (root == nullptr)
		return nullptr;
//	if (root->val == val && root->left == nullptr)
//		return nullptr;
//	if (root->val == val && root->left != nullptr)
//		return getLargest(root->left);
	if (root->val >= val)
		return predecessor(root->left, val);
	else {
		auto right = predecessor(root->right, val);
		return right == nullptr ? root : right;
	}
}

int secondLargest(TreeNode *root) {
	int largest = getLargest(root);
	auto secondLargestNode = predecessor(root, largest);
	return secondLargestNode->val;
}


// To execute C++, please define "int main()"
//int main() {
//	auto words = { "Hello, ", "World!", "\n" };
//	for (const string& word : words) {
//		cout << word;
//	}
//	return 0;
//}

