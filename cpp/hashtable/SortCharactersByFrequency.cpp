//
// Created by Guanqi Yu on 4/20/18.
//
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> count;
		for (auto c : s) {
			count[c] += 1;
		}
		for (auto p : count) {
			cout << p.first << " " << p.second << endl;
		}


		vector<pair<char, int>> pairs(count.begin(), count.end());

		sort(pairs.begin(), pairs.end(), [](pair<char, int> &p1, pair<char, int> &p2) {
			return p1.second > p2.second;
		});

		 for (auto &p : pairs) {
		     cout << p.first << " " << p.second << endl;
		 }

		ostringstream oss;
		for (auto &p : pairs) {
			string t = string(p.second, p.first);
			cout << t << endl;
			oss << t;
		}
		return oss.str();
	}
};

//int main() {
//	string s = "tree";
//	string res = Solution().frequencySort(s);
//	cout << res << endl;
//}