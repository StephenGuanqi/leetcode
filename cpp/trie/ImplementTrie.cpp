//
// Created by Guanqi Yu on 1/30/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Trie {
public:
	Trie(): root_(new TrieNode()) {}

	/*
	 * @param word: a word
	 * @return: nothing
	 */
	void insert(const string &word) {
		auto p = root_.get();
		for (const auto &c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->is_word = true;
	}

	/*
	 * @param word: A string
	 * @return: if the word is in the trie.
	 */
	bool search(string &word) const {
		auto p = find(word);
		return p && p->is_word;
	}

	/*
	 * @param prefix: A string
	 * @return: if there is any word in the trie that starts with the given prefix.
	 */
	bool startsWith(string &prefix) const {
		return find(prefix) != nullptr;
	}

private:
	struct TrieNode {
		TrieNode(): children(26, nullptr), is_word(false) {}

		~TrieNode() {
			for (auto child : children)
				if (child) delete child;
		}

		vector<TrieNode*> children;
		bool is_word;
	};

	// find the last trienode that match with the given prefix, return null if no such prefix
	const TrieNode *find(const string &prefix) const {
		auto p = root_.get();
		for (const char &c : prefix) {
			if (!p->children[c - 'a'])  return nullptr;
			p = p->children[c - 'a'];
		}
		return p;
	}

	std::unique_ptr<TrieNode> root_;
};