//
// Created by Guanqi Yu on 3/18/18.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	/**
	 * @param words: a set of stirngs
	 * @param target: a target string
	 * @param k: An integer
	 * @return: output all the strings that meet the requirements
	 */
	Solution(): root_(new TrieNode()) {}

	vector<string> kDistance(vector<string> &words, string &target, int k) {
		for (const auto &word : words)
			addWord(word);
		auto p = root_.get();
		// dp init
		// cols are target, rows are trie node(source string)
		int n = target.size();
		vector<int> prev(n + 1);
		for (int i = 0; i <= n; ++i) {
			prev[i] = i;
		}
		// dfs traverse
		vector<string> results;
		findKEdit(results, p, prev, target, 0, k);
		return results;
	}



private:
	struct TrieNode {
		TrieNode(): children(26, nullptr), isWord(false), word("") {}
		bool isWord;
		vector<TrieNode*> children;
		string word;

		~TrieNode() {
			for (auto child : children)
				if(child)   delete child;
		}
	};

	void addWord(const string &word) {
		auto p = root_.get();
		for (const auto &c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->isWord = true;
		p->word = word;
	}

	void findKEdit(vector<string> &results, TrieNode *node, vector<int> prev,
	               string &target, int depth, int k) {
		if (node->isWord && prev.back() <= k) {
			results.push_back(node->word);
		}
		int n = target.size();
		// dp
		for (int i = 0; i < 26; ++i) {
			if (!node->children[i])     continue;
			vector<int> next(n + 1);
			next[0] = depth + 1;
			for (int j = 1; j <= n; ++j) {
				next[j] = min(prev[j] + 1, min(next[j - 1] + 1, prev[j - 1] + 1));
				if (target[j - 1] - 'a' == i)
					next[j] = min(next[j], prev[j - 1]);
			}
			findKEdit(results, node->children[i], next, target, depth + 1, k);
		}
	}

	unique_ptr<TrieNode> root_;
};