//
// Created by Guanqi Yu on 3/24/18.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		return check(s, dict);
	}

private:
	bool check(string s, unordered_set<string> &wordDict) {
		if (memo_.count(s))
			return memo_[s];
		if (s.empty())  return true;
		for (int i = s.size() - 1; i >= 0; --i) {
			string rightSub = s.substr(i, s.size() - i);
			if (!wordDict.count(rightSub))   continue;
			string leftSub = s.substr(0, i);
//			bool res = check(leftSub, wordDict);
//			memo_[leftSub] = res;
			memo_[leftSub] = check(leftSub, wordDict);
			if (memo_[leftSub])     return true;
		}
		return false;
	}

	unordered_map<string, bool> memo_;
};

//int main() {
//	string s = "leetcode";
//	vector<string> dict = {"leet", "code"};
//	cout << (Solution().wordBreak(s, dict) ? "true" : "false") << endl;
//}