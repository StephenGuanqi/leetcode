//
// Created by Guanqi Yu on 1/3/18.
//
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		dict.insert(beginWord);
		unordered_map<string, int> dist; // each level's words' closest distance from beginNode
		unordered_map<string, vector<string>> prevWords; // each level's words' previous words in previous level
		vector<vector<string>> result;
		vector<string> path;
		bool found = bfs(beginWord, endWord, dict, dist);
		if (!found) return result;
		dfs(beginWord, dict, dist, result, path, endWord);
		return result;
	}
private:
	// also use dist as hash_Set
	bool bfs(const string &beginWord, const string &endWord,
	         const unordered_set<string> &dict, unordered_map<string,int> &dist) {
		queue<string> q;
		dist[beginWord] = 0;
		q.push(beginWord);
		while (!q.empty()) {
			string currWord = q.front();q.pop();
			if (currWord == endWord) return true;
			auto nextWords = getNextWords(currWord, dict);
			for (auto nextWord : nextWords) {
				if (dist.count(nextWord))   continue;
				dist[nextWord] = dist[currWord] + 1;
				q.push(nextWord);
			}
		}
		return false;
	}

	void dfs(const string &beginWord,
	         const unordered_set<string> &dict, unordered_map<string,int> &dist,
	         vector<vector<string>> &result, vector<string> &path, string current) {
		path.push_back(current);
		if (current == beginWord) {
			result.emplace_back(path.rbegin(), path.rend());
		} else {
			auto nextWords = getNextWords(current, dict);
			for (auto nextWord : nextWords) {
				if (!dist.count(nextWord) || dist[nextWord] + 1 != dist[current])   continue;
				dfs(beginWord, dict, dist, result, path, nextWord);
			}
		}
		path.pop_back();
	}

	vector<string> getNextWords(string word, const unordered_set<string> &dict) {
		vector<string> next_words;
		for (int i = 0; i < word.size(); ++i) {
			char old = word[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				word[i] = c;
				if (c == old || !dict.count(word))  continue;
				next_words.push_back(word);
			}
			word[i] = old;
		}
		return next_words;
	}
};


class Solution2 {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_map<string, int> dist; // each level's words' closest distance from beginNode
		unordered_map<string, vector<string>> prevWords; // each level's words' previous words in previous level
		vector<vector<string>> result;
		vector<string> path;
		bool found = bfs(beginWord, endWord, dict, dist, prevWords);
		if (!found) return result;
		dfs(beginWord, endWord, dist, prevWords, result, path);
		return result;
	}
private:
	bool bfs(const string &beginWord, const string &endWord,
	         const unordered_set<string> &dict, unordered_map<string, int> &dist,
	         unordered_map<string, vector<string>> &prevWords) {
		queue<string> q;
		q.push(beginWord);
		dist[beginWord] = 0;
		while (!q.empty()) {
			string curWord = q.front(); q.pop();
			if (curWord == endWord)    return true;
			auto nextWords = getNextWords(curWord, dict);
			for (auto nextWord : nextWords) {
				prevWords[nextWord].push_back(curWord);
				if (dist.count(nextWord)) continue;
				dist[nextWord] = dist[curWord] + 1;
				q.push(nextWord);
			}
		}
		return false;
	}

	void dfs(const string &beginWord, string current,
	         const unordered_map<string, int> &dist, const unordered_map<string, vector<string>> &prevWords,
	         vector<vector<string>> &result, vector<string> &path) {
		path.push_back(current);
		if (current == beginWord) {
			result.emplace_back(path.rbegin(), path.rend());
		} else {
			auto prevs = prevWords.find(current)->second;
			for (auto prev : prevs) {
				if (dist.find(prev)->second + 1 != dist.find(current)->second)
					continue;
				dfs(beginWord, prev, dist, prevWords, result, path);
			}
		}
		path.pop_back();
	}

	vector<string> getNextWords(string word, const unordered_set<string> &dict) {
		vector<string> next_words;
		for (int i = 0; i < word.size(); ++i) {
			char old = word[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				word[i] = c;
				if (c == old || !dict.count(word))  continue;
				next_words.push_back(word);
			}
			word[i] = old;
		}
		return next_words;
	}

};