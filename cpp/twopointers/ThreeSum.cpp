//
// Created by Guanqi Yu on 1/4/18.
//

#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	 * @param numbers: Give an array numbers of n integer
	 * @return: Find all unique triplets in the array which gives the sum of zero.
	 */
	vector<vector<int>> threeSum(vector<int> &numbers) {
		vector<vector<int>> results;
		if (numbers.empty())    return results;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); ++i) {
			// search tripe start with numbers[i], if duplicate, continue
			if (i > 0 && numbers[i] == numbers[i -1])   continue;
			twoSum(numbers, i + 1, numbers.size() - 1, -numbers[i], results);
		}
		return results;
	}
private:
	void twoSum(vector<int> &numbers, int start, int end, int target,
	            vector<vector<int>> &results) {
		while (start < end) {
			int sum = numbers[start] + numbers[end];
			if (sum == target) {
				vector<int> triple = {-target, numbers[start], numbers[end]};
				results.push_back(triple);
				++start;
				--end;
				while (start < end && numbers[start] == numbers[start - 1])
					++start;
				while (start < end && numbers[end] == numbers[end + 1])
					--end;
			} else if (sum > target) {
				--end;
			} else {
				++start;
			}
		}
	}
};