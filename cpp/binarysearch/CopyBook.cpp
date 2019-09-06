//
// Created by Guanqi Yu on 2/12/18.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <numeric>

using namespace std;


class Solution {
public:
	/*
	 * @param pages: an array of integers
	 * @param k: An integer
	 * @return: an integer
	 */
	int copyBooks(vector<int> &pages, int k) {
		if (pages.empty() || k == 0)  return 0;
		int max_page = *max_element(pages.begin(), pages.end());
		if (k >= pages.size())  return max_page;
		int sum = accumulate(pages.begin(), pages.end(), 0);
		if (k == 1) return sum;

		int start = max_page, end = sum;
		while (start + 1 <  end) {
			int mid = start + (end - start) / 2;
			if (countCopiers(mid, pages) > k) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}
		if (countCopiers(start, pages) <= k)
			return start;
		return end;
	}

private:
	int countCopiers(int slowest_limit, vector<int> &pages) {
		int count = 0;
		int accum = 0;
		for (auto page : pages) {
			if (accum + page > slowest_limit) {
				++count;
				accum = 0;
			}
			accum += page;
		}
		++count;
		return count;
	}
};

//int main() {
//	vector<int> pages = {3, 2, 4};
//	Solution().copyBooks(pages, 2);
//}