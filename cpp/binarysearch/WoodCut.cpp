//
// Created by Guanqi Yu on 2/12/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
	/*
	 * @param L: Given n pieces of wood with length L[i]
	 * @param k: An integer
	 * @return: The maximum length of the small pieces
	 */
	int woodCut(vector<int> &L, int k) {
		if (L.empty())  return 0;
		int max_length = *max_element(L.begin(), L.end());
		// binary search
		int l = 1, r = max_length;
		while (l + 1 <  r) {
			int mid = l + (r - l) / 2;
			if (checkValid(L, k, mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		if (checkValid(L, k, r))
			return r;
		if (checkValid(L, k, l))
			return l;
		return 0;
	}

private:
	bool checkValid(vector<int> &L, int k, int wood_length) {
		int amount = 0;
		for (auto l : L) {
			amount += l / wood_length;
			if (amount >= k)
				return true;
		}
		return false;
	}
};