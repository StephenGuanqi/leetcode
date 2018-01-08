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
	 * @param head: n
	 * @return: The new head of reversed linked list.
	 */
	ListNode *reverse(ListNode *head) {
		ListNode *prev = nullptr;
		ListNode *current = head;
		while (current != nullptr) {
			ListNode *tmp = current->next;
			current->next = prev;
			prev = current;
			current = tmp;
		}
		return prev;
	}
};