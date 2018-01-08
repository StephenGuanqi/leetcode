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

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
	/*
	 * @param head: The head of linked list.
	 * @return: nothing
	 */
	void reorderList(ListNode * head) {
		if (head == nullptr || head->next == nullptr)    return;
		ListNode *mid = findMid(head);
		ListNode *tail = reverse(mid->next);
		mid->next = nullptr;
		mergeTwoLists(head, tail);
	}

private:
	// passed in list has at least two nodes
	// odd nodes, return mid; even nodes, return n/2 - 1 th node
	ListNode *findMid(ListNode *head) {
		ListNode *slow = head, *fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode *reverse(ListNode *head) {
		ListNode *newHead = nullptr;
		while (head != nullptr) {
			ListNode *tmp = head->next;
			head->next = newHead;
			newHead = head;
			head = tmp;
		}
		return newHead;
	}

	void mergeTwoLists(ListNode *node1, ListNode *node2) {
		ListNode dum(0);
		int index = 0;
		ListNode *dummy = &dum;
		while (node1 != nullptr && node2 != nullptr) {
			if (index % 2 == 0) {
				dummy->next = node1;
				node1 = node1->next;
			} else {
				dummy->next = node2;
				node2 = node2->next;
			}
			dummy = dummy->next;
			++index;
		}
		if (node1 != nullptr)   dummy->next = node1;
		if (node2 != nullptr)   dummy->next = node2;
	}

};