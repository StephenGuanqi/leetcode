//
// Created by Guanqi Yu on 1/5/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;


class ListNode {
public:
	int val;
	ListNode *next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)    return nullptr;
		ListNode dummy(0);
		dummy.next = head;
		ListNode *current = &dummy;
		while (current != nullptr) {
			current = reverseNextK(current, k);
		}
		return dummy.next;
	}

private:
	// return the next node's previous node to be reverse, which is n1
	// head is not null
	ListNode *reverseNextK(ListNode *head, int k) {
		// find n1 and nk
		ListNode *n1 = head->next;
		ListNode *nk = head;
		for (int i = 0; i < k; ++i) {
			nk = nk->next;
			if (nk == nullptr)
				return nullptr;
		}

		// reverse
		ListNode *nknext = nk->next;
		ListNode *prev = head;
		ListNode *current = n1;
		while (current != nknext) {
			ListNode *tmp = current->next;
			current->next = prev;
			prev = current;
			current = tmp;
		}

		// connect
		n1->next = nknext;
		head->next = nk;
		return n1;
	}
};