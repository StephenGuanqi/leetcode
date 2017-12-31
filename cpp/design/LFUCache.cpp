//
// Created by Guanqi Yu on 12/29/17.
//
#include <list>
#include <unordered_map>

using namespace std;

struct Node {
	int key;
	int value;
	int freq;
};

class LFUCache {
	/**
	 * similar to the thought of segregate list
	 */
public:
	LFUCache(int capacity) {
		capacity_ = capacity;
	}

	int get(int key) {
		auto it = m_.find(key);
		if (it == m_.cend())    return -1;
		touch(it->second);
		return it->second->value;
	}

	void put(int key, int value) {
		auto it = m_.find(key);
		if (it != m_.cend()) {
			it->second->value = value;
			touch(it->second);
			return;
		}
		if (size == capacity_) {

		}
		size++;

	}

private:
	void touch(list<Node>::iterator &it) {
		list<Node> &old_list = cache_[it->freq];
		++it->freq;
		list<Node> &new_list = cache_[it->freq];
		new_list.splice(new_list.begin(), old_list, it);
	}
	int capacity_;
	int size ;
	int minFreq_; // key of the min Freq
	unordered_map<int, list<Node>::iterator> m_; // {key, list<Node>::it}
	unordered_map<int, list<Node>> cache_; // {freq, list<Node>}
};