//
// Created by Guanqi Yu on 12/29/17.
//
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
	/**
	 * use reference as possible. All functions have no loacal temp variable
	 * key: no matter get or set, it's just a set of {key, value} collections and hashtable O(1) lookup
	 * each operation update the node's relative position (delete and insert) ---> order
	 */
	LRUCache(int capacity) {
		capacity_ = capacity;
	}

	int get(int key) {
		const auto it = m_.find(key);
		if (it == m_.cend())    return -1;
		cache_.splice(cache_.begin(), cache_, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m_.find(key);
		// if key exist
		if (it != m_.cend()) {
			it->second->second = value;
			cache_.splice(cache_.begin(), cache_, it->second);
			return;
		}

		// if capacity is full, evict
		if (capacity_ == cache_.size()) {
			const auto &node = cache_.back();
			cache_.pop_back();
			m_.erase(node.first);
		}

		cache_.emplace_front(key, value);
		// m_.insert({key, cache_.begin()});
		m_[key] = cache_.begin(); // faster
	}
private:
	int capacity_;
	list<pair<int, int>> cache_;
	unordered_map<int, list<pair<int, int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */