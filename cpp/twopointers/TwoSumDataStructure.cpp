//
// Created by Guanqi Yu on 1/8/18.
//
#include <list>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;


class TwoSum {
public:
	/*
	 * @param number: An integer
	 * @return: nothing
	 */
	void add(int number) {
		nums.insert(number);
	}

	/*
	 * @param value: An integer
	 * @return: Find if there exists any pair of numbers which sum is equal to the value.
	 */
	bool find(int value) {
		for (int num : nums) {
			int target_count = value - num == num ? 2 : 1;
			if (nums.count(value - num) >= target_count)
				return true;
		}
		return false;
	}
private:
	unordered_multiset<int> nums;
};