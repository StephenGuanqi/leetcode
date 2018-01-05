//
// Created by Guanqi Yu on 1/2/18.
//
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<string> q;
		unordered_set<string> visited;
		int dist = 0;
		q.push(beginWord);
		visited.insert(beginWord);
		while (!q.empty()) {
			int sz = q.size();
			++dist;
			for (int i = 0; i < sz; ++i) {
				string word = q.front(); q.pop();
				auto nextWords = getNextWords(word, dict);
				for (string nextWord : nextWords) {
					if (nextWord == endWord)    return dist + 1;
					if (visited.count(nextWord))    continue;
					q.push(nextWord);
					visited.insert(nextWord);
				}
			}
		}
		return 0;
	}

private:
	vector<string> getNextWords(string &word, const unordered_set<string> &dict) {
		vector<string> next_words;
		for (int i = 0; i < word.size(); ++i) {
			char old = word[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				if (c == old)   continue;
				word[i] = c;
				if (dict.count(word))
					next_words.push_back(word);
			}
			word[i] = old;
		}
		return next_words;
	}
};

class Solution2 {
	/**
	 * 96 ms
	 */
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<string> q;
		int dist = 0;
		q.push(beginWord);
		while (!q.empty()) {
			int sz = q.size();
			++dist;
			for (int i = 0; i < sz; ++i) {
				string word = q.front(); q.pop();
				// bfs
				// enqueue all next words which exist in dictionary
				for (int i = 0; i < word.size(); ++i) {
					char old = word[i];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (old == c)   continue;
						word[i] = c;
						if (!dict.count(word))  continue;
						if (word == endWord)    return dist + 1;
						dict.erase(word);
						q.push(word);
					}
					word[i] = old;
				}
			}
		}
		return 0;
	}
};

