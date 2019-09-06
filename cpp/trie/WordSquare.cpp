//
// Created by Guanqi Yu on 3/25/18.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
	Solution() : root_(new TrieNode()) {}

	vector<vector<string>> wordSquares(vector<string>& words) {
		for (const auto &word : words)
			insert(word);
		vector<vector<string>> res;
		vector<string> current;
		dfs(res, current);
		return res;
	}

private:
	void dfs(vector<vector<string>> &res, vector<string> &current) {
		if (!current.empty() && current.size() == current[0].size()) {
			res.push_back(current);
			return;
		}

		string prefix = "";
		int idx = current.size();
		for (const auto &word : current)
			prefix += word[idx];
		vector<string> words = startWith(prefix);

		for (const auto &word : words) {
			current.push_back(word);
			dfs(res, current);
			current.pop_back();
		}
	}

	struct TrieNode {
		TrieNode(): children(26), isWord(false), word("") {}
		~TrieNode() {
			for (const auto &child : children)
				if (child)  delete child;
		}
		vector<TrieNode*> children;
		bool isWord;
		string word;
	};

	void insert(const string &word) {
		auto p = root_.get();
		for (const char &c : word) {
			if (!p->children[c - 'a'])
				p->children[c - 'a'] = new TrieNode();
			p = p->children[c - 'a'];
		}
		p->isWord = true;
		p->word = word;
	}

	vector<string> startWith(string &prefix) {
		if (memo_.count(prefix))    return memo_[prefix];
		vector<string> res;
		auto prefixLastNode = find(prefix);
		if (prefixLastNode) {
			findAll(prefixLastNode, res);
		}
		memo_[prefix] = res;
		return res;
	}

	void findAll(TrieNode *node, vector<string> &res) {
		if (node->isWord)
			res.push_back(node->word);
		for (const auto &child : node->children) {
			if (child)
				findAll(child, res);
		}
	}

	TrieNode *find(const string &prefix) {
		auto p = root_.get();
		for (const char &c : prefix) {
			if (!p->children[c - 'a'])  return nullptr;
			p = p->children[c - 'a'];
		}
		return p;
	}

	unique_ptr<TrieNode> root_;
	unordered_map<string, vector<string>> memo_; // {prefix, words}
};

//int main() {
//	vector<string> words = {"area","lead","wall","lady","ball"};
//	auto res = Solution().wordSquares(words);
//	for (auto &words : res) {
//		for (auto &word : words)
//			cout << word << " " << endl;
//		cout << endl;
//		cout << endl;
//	}
//}