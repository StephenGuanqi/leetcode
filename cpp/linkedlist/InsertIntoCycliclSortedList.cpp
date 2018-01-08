//
// Created by Guanqi Yu on 1/7/18.
//

#include <iostream>
#include <algorithm>
#include <queue>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};


using namespace std;

class Solution {
public:
	/*
	 * @param node: a list node in the list
	 * @param x: An integer
	 * @return: the inserted new list node
	 */
	ListNode * insert(ListNode * node, int x) {
		if (node == nullptr) {
			node = new ListNode(x);
			node->next = node;
			return node;
		}
		ListNode *current = node;
		ListNode *prev = nullptr;
		do {
			prev = current;
			current = current->next;
			if (prev->val <= x && x <= current->val)
				break;
			if (prev->val > current->val && (x < current->val || x > prev->val))
				break;
		} while (current != node);

		ListNode *newNode = new ListNode(x);
		newNode->next = current;
		prev->next = newNode;
		return newNode;
	}
};