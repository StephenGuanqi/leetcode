//
// Created by Guanqi Yu on 2/1/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		int n = flowers.size();
		if (n == 0 && k >= n - 1)   return -1;
		set<int> xs;
		for (int i = 0; i < flowers.size(); ++i) {
			auto r = xs.insert(flowers[i]).first;
			auto l = r;
			if (++r != xs.end() && *r == flowers[i] + k + 1)
				return i + 1;
			if (l != xs.begin() && *(--l) == flowers[i] - k - 1)
				return i + 1;
		}
		return -1;
	}
};

class Solution2 {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		int n = flowers.size();
		if (n == 0 && k >= n - 1)   return -1;
		std::unique_ptr<char[]> f(new char[n + 1]);
		memset(f.get(), 0, (n + 1)*sizeof(char));
		for (int i = 0; i < flowers.size(); ++i)
			if(check(f.get(), k, n, flowers[i]))
				return i + 1;
		return -1;
	}

private:
	bool check(char *f, int k, int n, int x) {
		f[x] = 1;
		if (x + k + 1 <= n && f[x + k + 1]) {
			for (int i = 1; i <= k; ++i)
				if (f[x + i])   return false;
			return true;
		}

		if (x - k - 1 >= 0 && f[x - k - 1]) {
			for (int i = 1; i <= k; ++i)
				if (f[x - i])   return false;
			return true;
		}

		return false;
	}
};