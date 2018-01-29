//
// Created by Guanqi Yu on 1/8/18.
//



#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	/**
	 * cache ---> static variable
	 */
public:
	int nthUglyNumber(int n) {
		static vector<int> nums;
		if (nums.empty()) {
			for (long a = 1; a <= INT_MAX; a *= 2)
				for (long b = a; b <= INT_MAX; b *= 3)
					for (long c = b; c <= INT_MAX; c *= 5)
						nums.push_back(c);
			std::sort(nums.begin(), nums.end());
		}
		return nums[n - 1];
	}
};


class Solution2 {
public:
	/*
	 * @param n: An integer
	 * @return: the nth prime number as description.
	 */
	int nthUglyNumber(int n) {
		static vector<int> result(1, 1);
		int i = 0, j = 0, k = 0;
		while (result.size() < n) {
			result.push_back(min(result[i] * 2, min(result[j] * 3, result[k] * 5)));
			if (result.back() == result[i] * 2) ++i;
			if (result.back() == result[j] * 3) ++j;
			if (result.back() == result[k] * 5) ++k;
		}
		return result[n - 1];
	}
};