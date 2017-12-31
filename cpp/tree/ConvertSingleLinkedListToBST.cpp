//
// Created by Guanqi Yu on 12/26/17.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val_) : val(val_) { }
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)    return nullptr;
		return listToBST(head, nullptr);
	}

	TreeNode *listToBST(ListNode *head, ListNode *tail) {
		ListNode *fast = head, *slow = head;
		if (head == tail)   return nullptr;
		while (fast != tail && fast->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode *root = new TreeNode(slow->val);
		root->left = listToBST(head, slow);
		root->right = listToBST(slow->next, tail);
		return root;
	}

};