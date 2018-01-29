//
// Created by Guanqi Yu on 1/8/18.
//
#include <list>
#include <unordered_map>
#include <vector>
#include <unordered_set>

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
	/**
	 * @param hashTable: A list of The first node of linked list
	 * @return: A list of The first node of linked list which have twice size
	 */
	vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
		vector<ListNode*> newTable(hashTable.size() * 2, nullptr);
		for (int i = 0; i < hashTable.size(); ++i) {
			ListNode *cur = hashTable[i];
			while (cur != nullptr) {
				ListNode *tmp = cur->next;
				cur->next = nullptr;
				moveNode(newTable, cur);
				cur = tmp;
			}
		}
		return newTable;
	}
private:
	void moveNode(vector<ListNode*> &hashTable, ListNode *node) {
		int number = node->val, TABLE_SIZE = hashTable.size();
		int hash = (number % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
		if (hashTable[hash] == nullptr)
			hashTable[hash] = node;
		else
			addListNode(hashTable[hash], node);
	}

	void addListNode(ListNode *head, ListNode *node) {
		if (head->next == nullptr)
			head->next = node;
		else
			addListNode(head->next, node);
	}
};
