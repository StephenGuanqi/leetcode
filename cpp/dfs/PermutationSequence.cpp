//
// Created by Guanqi Yu on 3/24/18.
//


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> visited(n + 1);
		vector<int> permutation;
		string result = "";
		getPermutation(n, k, visited, permutation, result);
		return result;
	}

private:
	bool getPermutation(int n, int k, vector<int> &visited, vector<int> &permutation, string &result) {
		if (permutation.size() == n) {
			if (--k == 0) {
				for (auto num : permutation) {
					result += to_string(num);
				}
				return true;
			}
			return false;
		}
		bool res = false;
		for (int i = 1; i <= n; ++i) {
			if (visited[i]) continue;
			visited[i] = true;
			permutation.push_back(i);
			res = getPermutation(n, k, visited, permutation, result);
			if (res)    break;
			permutation.pop_back();
			visited[i] = false;
		}
		return res;
	}
};

//int main() {
//	int n = 2, k = 2;
//	Solution().getPermutation(n, k);
//}