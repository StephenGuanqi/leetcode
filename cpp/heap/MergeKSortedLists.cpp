//
// Created by Guanqi Yu on 12/21/17.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/**
	 * method 1
	 */
     struct compare {
         bool operator()(const ListNode* l, const ListNode* r) {
             return l->val > r->val;
         }
     };

     ListNode* mergeKLists(vector<ListNode*>& lists) {
         // priority_queue<ListNode*, vector<ListNode *>, compare> q(lists.cbegin(), lists.cend());
         priority_queue<ListNode *, vector<ListNode *>, compare> q;
         for(auto l : lists) {
             if(l)  q.push(l);
         }
         ListNode dummy(0);
         ListNode *tail = &dummy;
         while (!q.empty()) {
             ListNode *head = q.top();
             // if (head == nullptr) continue; // endless loop because never top, always null header
             q.pop();
             // if (head == nullptr) continue; // compare operator error because q has to heapify, and compare invoked on
             // the rest of null ptr
             if (head->next != nullptr) // compile error when lists has null ListNode element
                 q.push(head->next);
             // update node for global sorted order
             tail->next = head;
             tail = tail->next;
         }
         return dummy.next;
     }

	/**
	 * method two
	 */
	static bool heapComp(const ListNode *a, const ListNode *b) {
		return a->val > b->val;
	}

	ListNode *mergeKLists2(vector<ListNode *> &lists) {
		ListNode dummy(0);
		ListNode *tail = &dummy;
		vector<ListNode *> v;
		for (auto l : lists) if (l) v.push_back(l);
		make_heap(v.begin(), v.end(), heapComp);
		while (!v.empty()) {
			ListNode *maxhead = v.front();
			pop_heap(v.begin(), v.end(), heapComp);
			v.pop_back();
			if (maxhead->next != nullptr)
				v.push_back(maxhead->next);
			push_heap(v.begin(), v.end(), heapComp);
			tail->next = maxhead;
			tail = tail->next;
		}
		return dummy.next;
	}

};


class Solution2 {
public:
	/**
	 * Divide and Conquer
	 */
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty())  return nullptr;
		return mergeKLists(lists, 0, lists.size() - 1);
	}

private:
	ListNode *mergeKLists(vector<ListNode*> &lists, int start, int end) {
		if (end == start)   return lists[start];
		int mid = start + (end - start) / 2;
		ListNode *left = mergeKLists(lists, start, mid);
		ListNode *right = mergeKLists(lists, mid + 1, end);
		return mergeTwoSortedList(left, right);
	}

	ListNode *mergeTwoSortedList(ListNode *a, ListNode *b) {
		ListNode dummy(0);
		ListNode *tail = &dummy;
		while (a != nullptr && b != nullptr) {
			if (a->val < b->val) {
				tail->next = a;
				a = a->next;
			} else {
				tail->next = b;
				b = b->next;
			}
			tail = tail->next;
		}
		if (a != nullptr)   tail->next = a;
		if (b != nullptr)   tail->next = b;
		return dummy.next;
	}

};