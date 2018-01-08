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

class Solution {
public:
	/*
	 * @param head: The first node of linked list
	 * @param x: An integer
	 * @return: A ListNode
	 */
	ListNode * partition(ListNode * head, int x) {
		ListNode dumLeft(0);
		ListNode dumRight(0);
		ListNode *leftTail = &dumLeft;
		ListNode *rightTail = &dumRight;
		while (head != nullptr) {
			if (head->val < x) {
				leftTail->next = head;
				leftTail = head;
			} else {
				rightTail->next = head;
				rightTail = head;
			}
			head = head->next;
		}
		leftTail->next = dumRight.next;
		rightTail->next = nullptr;
		return dumLeft.next;
	}
};