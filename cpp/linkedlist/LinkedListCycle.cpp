//
// Created by Guanqi Yu on 1/6/18.
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

class Solution {
public:
	/*
	 * @param head: The first node of linked list.
	 * @return: True if it has a cycle, or false
	 */
	bool hasCycle(ListNode * head) {
		if (head == nullptr || head->next == nullptr)   return false;
		ListNode *slow = head, *fast = head->next;
		while (slow != fast) {
			if (fast == nullptr || fast->next == nullptr)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
	}

	ListNode * detectCycle(ListNode * head) {
		if (head == nullptr || head->next == nullptr)   return nullptr;
		ListNode *slow = head, *fast = head->next;
		while (slow != fast) {
			if (fast == nullptr || fast->next == nullptr)
				return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		}
		while (head != slow->next) {
			head = head->next;
			slow = slow->next;
		}
		return head;
	}
};