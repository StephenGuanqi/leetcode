//
// Created by Guanqi Yu on 1/31/18.
//

#include <vector>
#include <iostream>

using namespace std;

class WordDictionary {
public:
	WordDictionary(): root_(new TrieNode()) {}

	/*
	 * @param word: Adds a word into the data structure.
	 * @return: nothing
	 */
	void addWord(string &word) {
		auto p = root_.get();
		for (auto &c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->is_word = true;
	}

	/*
	 * @param word: A word could contain the dot character '.' to represent any one letter.
	 * @return: if the word is in the data structure.
	 */
	bool search(string &word) {
		if (word.empty())   return true;
		return search(root_.get(), word, 0);
	}

private:
	struct TrieNode {
		TrieNode(): children(26), is_word(false) {}

		~TrieNode() {
			for (auto &child : children)
				if (child)  delete child;
		}

		vector<TrieNode*> children;
		bool is_word;
	};

	bool search(TrieNode *node, string &word, int startIndex) {
		if (startIndex == word.size())
			return node->is_word;

		char c = word[startIndex];
		if (c != '.') {
			auto p = node->children[c - 'a'];
			if (!p)     return false;
			return search(p, word, startIndex + 1);
		} else {
			bool res = false;
			for (auto &child : node->children) {
				if (child)
					res = search(child, word, startIndex + 1);
				if (res)    break;
			}
			return res;
		}
	}

	unique_ptr<TrieNode> root_;
};