//
// Created by Guanqi Yu on 1/6/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include<unordered_map>
using namespace std;


struct RandomListNode {
	int label;
	RandomListNode *next, *random;

	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr) return nullptr;
		// copy nodes
		unordered_map < RandomListNode * , RandomListNode * > map;
		RandomListNode *current = head;
		while (current != nullptr) {
			RandomListNode *node = new RandomListNode(current->label);
			map[current] = node;
			current = current->next;
		}
		// copy edges
		current = head;
		while (current != nullptr) {
			auto node = map[current];
			node->next = map[current->next];
			/**
			 * Note here we can't guarantee current->random is not nullptr (should add if here)
			 * but since we use unordered_map, if it is nullptr, we just create one in map
			 */
			node->random = map[current->random];
			current = current->next;
		}
		return map[head];
	}


};


class Solution2 {
public:
	/**
	 * @param head: The head of linked list with a random pointer.
	 * @return: A new head of a deep copy of the list.
	 */
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)    return nullptr;
		// copy nodes and establish mapping
		RandomListNode *current = head;
		while (current != nullptr) {
			RandomListNode *node = new RandomListNode(current->label);
			RandomListNode *tmp = current->next;
			current->next = node;
			node->next = tmp;
			current = tmp;
		}
		// copy random edges
		current = head;
		while (current != nullptr) {
			auto node = current->next;
			if (current->random != nullptr)
				node->random = current->random->next;
			current = current->next->next;
		}
		// split
		RandomListNode *result = head->next;
		while (head != nullptr && head->next != nullptr) {
			auto node = head->next;
			head->next = node->next;
			head = node;
		}
		return result;
	}



};