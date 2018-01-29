//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
	/**
	 * O(n) Space
	 * O(n + klogn) Time
	 */
public:
	/*
	 * @param words: an array of string
	 * @param k: An integer
	 * @return: an array of string
	 */
	vector<string> topKFrequentWords(vector<string> &words, int k) {
		auto cmp = [] (pair<string, int> &p1, pair<string, int> &p2) {
			return p1.second != p2.second ? p1.second < p2.second :
			       p1.first > p2.first;
		};
		unordered_map<string, int> map;
		for (string word: words) {
			map[word] += 1;
		}
		vector<pair<string, int>> word_vecs(map.begin(), map.end());
		make_heap(word_vecs.begin(), word_vecs.end(), cmp);
		vector<string> ans;
		for (int i = 0; i < k; ++i) {
			pop_heap(word_vecs.begin(), word_vecs.end(), cmp);
			ans.push_back(word_vecs.back().first);
			word_vecs.pop_back();
		}
		return ans;
	}
};