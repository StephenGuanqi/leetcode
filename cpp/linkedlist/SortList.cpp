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
	/**
	 * Merge Sort
	 */
public:
	/*
	 * @param head: The head of linked list.
	 * @return: You should return the head of the sorted linked list, using constant space complexity.
	 */
	ListNode *sortList(ListNode * head) {
		if (head == nullptr || head->next == nullptr)    return head;
		ListNode *mid = findMid(head);
		ListNode *right = sortList(mid->next);
		mid->next = nullptr;
		ListNode *left = sortList(head);
		return mergeTwoSortedList(left, right);
	}

private:
	ListNode *findMid(ListNode *head) {
		ListNode *slow = head, *fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode *mergeTwoSortedList(ListNode *head1, ListNode *head2) {
		ListNode dummy(0);
		ListNode *tail = &dummy;
		while (head1 != nullptr && head2 != nullptr) {
			if (head1->val < head2->val) {
				tail->next = head1;
				head1 = head1->next;
			} else {
				tail->next = head2;
				head2 = head2->next;
			}
			tail = tail->next;
		}
		if (head1 != nullptr)   tail->next = head1;
		if (head2 != nullptr)   tail->next = head2;
		return dummy.next;
	}


};


class Solution2 {
	/**
	 * Quick Sort
	 */
public:
	/*
	 * @param head: The head of linked list.
	 * @return: You should return the head of the sorted linked list, using constant space complexity.
	 */
	ListNode *sortList(ListNode * head) {
		if (head == nullptr || head->next == nullptr)    return head;
		// partition
		ListNode leftDummy(0);
		ListNode rightDummy(0);
		ListNode equalDummy(0);
		ListNode *leftTail = &leftDummy;
		ListNode *rightTail = &rightDummy;
		ListNode *equalTail = &equalDummy;
		int val = findMid(head)->val;
		while (head != nullptr) {
			if (head->val < val) {
				leftTail->next = head;
				leftTail = head;
			} else if (head->val > val) {
				rightTail->next = head;
				rightTail = head;
			} else {
				equalTail->next = head;
				equalTail = head;
			}
			head = head->next;
		}
		leftTail->next = nullptr;
		equalTail->next = nullptr;
		rightTail->next = nullptr;

		// divide
		ListNode *leftHead = sortList(leftDummy.next);
		ListNode *rightHead = sortList(rightDummy.next);

		// merge
		return concat(leftHead, equalDummy.next, rightHead);
	}

private:
	// left or right could be nullptr
	ListNode *concat(ListNode *left, ListNode *mid, ListNode *right) {
		ListNode dummy(0);
		ListNode *tail = &dummy;
		tail->next = left; tail = getTail(tail);
		tail->next = mid; tail = getTail(tail);
		tail->next = right;
		return dummy.next;
	}

	ListNode *getTail(ListNode *head) {
		if (head == nullptr)    return nullptr;
		while (head->next != nullptr)
			head = head->next;
		return head;
	}

	ListNode *findMid(ListNode *head) {
		ListNode *slow = head, *fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

//int main() {
//	ListNode n1(1);
//	ListNode n2(-1);
//	n1.next = &n2;
//	Solution().sortList(&n1);
//}