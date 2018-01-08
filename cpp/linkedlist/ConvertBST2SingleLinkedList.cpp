//
// Created by Guanqi Yu on 1/8/18.
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

struct DoublyListNode {
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};


class Solution {
public:
	/*
	 * @param root: The root of tree
	 * @return: the head of doubly list node
	 */
	DoublyListNode * bstToDoublyList(TreeNode * root) {
		if (root == nullptr)    return nullptr;
		auto res = helper(root);
		return res.first;
	}
private:
	// converted result: head and tail of converted linked list on node root
	pair<DoublyListNode*, DoublyListNode*> helper(TreeNode *root) {
		if (root == nullptr)    return {nullptr, nullptr};
		auto leftRes = helper(root->left);
		auto rightRes = helper(root->right);

		DoublyListNode *mid = new DoublyListNode(root->val);
		pair<DoublyListNode*, DoublyListNode*> res = {nullptr, nullptr};

		if (leftRes.second == nullptr)  {
			res.first = mid;
		} else {
			leftRes.second->next = mid;
			mid->prev = leftRes.second;
			res.first = leftRes.first;
		}
		if (rightRes.first == nullptr) {
			res.second = mid;
		} else {
			mid->next = rightRes.first;
			rightRes.first->prev = mid;
			res.second = rightRes.second;
		}

		return res;
	}
};


class Solution2 {
public:
	/*
	 * @param root: The root of tree
	 * @return: the head of doubly list node
	 */
	DoublyListNode * bstToDoublyList(TreeNode * root) {
		if (root == nullptr)    return nullptr;
		stack<TreeNode*> st;
		TreeNode *current = root;
		DoublyListNode dummy(0);
		DoublyListNode *tail = &dummy;
		while (current != nullptr || !st.empty()) {
			while (current != nullptr) {
				st.push(current);
				current = current->left;
			}
			current = st.top(); st.pop();
			DoublyListNode *newNode = new DoublyListNode(current->val);
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			current = current->right;
		}
		return dummy.next;
	}
};