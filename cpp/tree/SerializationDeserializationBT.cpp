////
//// Created by Guanqi Yu on 12/21/17.
////

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Non-recursive, level order build
 */
string serialize(TreeNode* root) {
	if (root == nullptr) return "[]";
	string output;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		if (node == nullptr) {
			output += "null,";
			continue;
		}
		output += to_string(node->val) + ",";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 1) + "]";
}


TreeNode* deserialize(string data) {
	string input = data.substr(1, data.length() - 2);
	if (!input.size()) return nullptr; // not input == Null
	string item;
	stringstream ss(input);
	getline(ss, item, ',');
	TreeNode *root = new TreeNode(stoi(item));
	queue<TreeNode*> q;
	q.push(root);
	while(true) {
		TreeNode *node = q.front();
		q.pop();

		if (!getline(ss, item, ','))
			break;
		if (item != "null") {
			node->left = new TreeNode(stoi(item));
			q.push(node->left);
		}

		if (!getline(ss, item, ','))
			break;
		if (item != "null") {
			node->right = new TreeNode(stoi(item));
			q.push(node->right);
		}
	}

	return root;
}
//
//
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		TreeNode *t1 = deserialize(line);
//
//		string out = serialize(t1);
//		cout << out << endl;
//	}
//	return 0;
//}

/**
 * recursive is much faster
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream oss;
		serialize(root, oss);
		return oss.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream iss(data);
		return deserialize(iss);
	}
private:

	void serialize(TreeNode* node, ostringstream &oss) {
		if (node == nullptr) {
			oss << "# ";
		} else {
			oss << node->val << ' ';
			serialize(node->left, oss);
			serialize(node->right, oss);
		}
	}

	TreeNode *deserialize(istringstream &iss) {
		string item;
		iss >> item;
		if (item == "#")    return nullptr;
		TreeNode *root = new TreeNode(stoi(item));
		root->left = deserialize(iss);
		root->right = deserialize(iss);
		return root;
	}

};