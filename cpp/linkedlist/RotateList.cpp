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
	 * @param head: the List
	 * @param k: rotate to the right k places
	 * @return: the list after rotation
	 */
	ListNode * rotateRight(ListNode * head, int k) {
		if (head == nullptr)    return nullptr;
		int n = getLength(head);
		k = k % n;
		ListNode dummy(0);
		dummy.next = head;
		ListNode *tail = &dummy;
		head = &dummy;

		for (int i = 0; i < k; ++i) {
			head = head->next;
		}
		while (head->next != nullptr) {
			tail = tail->next;
			head = head->next;
		}

		head->next = dummy.next;
		dummy.next = tail->next;
		tail->next = nullptr;
		return dummy.next;
	}
private:
	int getLength(ListNode *head) {
		int n = 0;
		while (head != nullptr) {
			++n;
			head = head->next;
		}
		return n;
	}
};