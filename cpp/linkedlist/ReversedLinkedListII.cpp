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


class Solution1 {
public:
	/*
	 * @param head: ListNode head is the head of the linked list
	 * @param m: An integer
	 * @param n: An integer
	 * @return: The head of the reversed ListNode
	 */
	ListNode * reverseBetween(ListNode * head, int m, int n) {
		if (m >= n || head == nullptr)
			return head;
		// we are sure 1 <= m <= n <= length
		ListNode dummy(0);
		dummy.next = head;

		ListNode *mPrev = findKthNode(&dummy, m - 1);
		ListNode *mNode = mPrev->next;
		ListNode *nNode = findKthNode(mPrev, n - m  + 1);
		ListNode *nNext = nNode->next;

		// reverse
		nNode->next = nullptr;
		reverse(mNode);

		mPrev->next = nNode;
		mNode->next = nNext;

		return dummy.next;
	}

	// need dummy
	ListNode *findKthNode(ListNode *head, int k) {
		for (int i = 0; i < k; ++i) {
			head = head->next;
			if (head == nullptr)
				return nullptr;
		}
		return head;
	}

	void reverse(ListNode *head) {
		ListNode *prev = nullptr;
		while (head != nullptr) {
			ListNode *tmp = head->next;
			head->next = prev;
			prev = head;
			head = tmp;
		}
	}

};

class Solution {
public:
	/*
	 * @param head: ListNode head is the head of the linked list
	 * @param m: An integer
	 * @param n: An integer
	 * @return: The head of the reversed ListNode
	 */
	ListNode * reverseBetween(ListNode * head, int m, int n) {
		if (m >= n || head == nullptr)
			return head;
		// we are sure 1 <= m <= n <= length
		ListNode dummy(0);
		dummy.next = head;
		ListNode *current = &dummy;

		// find mth node
		for (int i = 1; i < m; ++i) {
			current = current->next;
			if (current == nullptr)
				return nullptr;
		}

		ListNode *mNode = current->next;
		ListNode *mPrev = current;
		ListNode *nNode = mNode;
		ListNode *postNode = nNode->next;
		// reverse
		for (int i = m; i < n; ++i) {
			if (postNode == nullptr)   return nullptr;
			ListNode *tmp = postNode->next;
			postNode->next = nNode;
			nNode = postNode;
			postNode = tmp;
		}

		// connect
		mPrev->next = nNode;
		mNode->next = postNode;
		return dummy.next;
	}
};