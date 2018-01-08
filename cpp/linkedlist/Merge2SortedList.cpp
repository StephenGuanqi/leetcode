//
// Created by Guanqi Yu on 1/5/18.
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
	 * @param l1: ListNode l1 is the head of the linked list
	 * @param l2: ListNode l2 is the head of the linked list
	 * @return: ListNode head of linked list
	 */
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		// write your code here
		ListNode dummy(0);
		ListNode *tail = &dummy;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				tail->next = l1;
				tail = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr)  tail->next = l1;
		if (l2 != nullptr)  tail->next = l2;
		return dummy.next;
	}
};