//
// Created by Guanqi Yu on 1/5/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param numbers: Give an array numbers of n integer
	 * @param target: An integer
	 * @return: return the sum of the three integers, the sum closest target.
	 */
	int threeSumClosest(vector<int> &numbers, int target) {
		if (numbers.empty())    return 0;
		sort(numbers.begin(), numbers.end());
		int closest = 0;
		int minDiff = INT_MAX;
		for (int i = 0; i < numbers.size(); ++i) {
			if (i != 0 && numbers[i] == numbers[i - 1]) continue;
			int start = i + 1, end = numbers.size() - 1;
			while (start < end) {
				int sum = numbers[i] + numbers[start] + numbers[end];
				if (sum > target) {
					closest = minDiff < sum - target ? closest : sum;
					minDiff = min(minDiff, sum - target);
					--end;
				} else if (sum < target) {
					closest = minDiff < target - sum ? closest : sum;
					minDiff = min(minDiff, target - sum);
					++start;
				} else { // find sum == target
					return sum;
				}
			}
		}
		return closest;
	}
};