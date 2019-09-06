//
// Created by Guanqi Yu on 1/31/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
	Solution(): root_(new TrieNode()) {}

	/*
	 * @param board: A list of lists of character
	 * @param words: A list of string
	 * @return: A list of string
	 */
	vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
		// build dict
		for (auto &word : words) {
			insert(word);
		}
		// dfs
		unordered_set<string> ans;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				find(board, i, j, root_.get(), ans);
			}
		}
		return vector<string>(ans.begin(), ans.end());
	}

private:
	struct TrieNode {
		TrieNode(): children(26), is_word(false) {}

		~TrieNode() {
			for (auto &child : children)
				if(child)   delete child;
		}
		vector<TrieNode*> children;
		string word;
		bool is_word;
	};


	void find(vector<vector<char>> &board, int x, int y, TrieNode *node, unordered_set<string> &ans) {
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())    return;

		char c = board[x][y];
		// visited
		if (c == '#')     return;
		// no matched in dictionary
		if (node->children[c - 'a'] == nullptr)     return;
		// add answer if possible
		auto next = node->children[c - 'a'];
		if (next->is_word)
			ans.insert(next->word);

		board[x][y] = '#';
		find(board, x + 1, y, next, ans);
		find(board, x, y + 1, next, ans);
		find(board, x - 1, y, next, ans);
		find(board, x, y - 1, next, ans);
		board[x][y] = c;
	}

	void insert(string &word) {
		auto p = root_.get();
		for (auto &c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->is_word = true;
		p->word = word;
	}

	unique_ptr<TrieNode> root_;
};