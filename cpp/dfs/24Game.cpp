//
// Created by Guanqi Yu on 3/30/18.
//

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;



class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		double eps = 0.001;
		vector<double> numsd(nums.begin(), nums.end());
		return judgePoint24(numsd, eps);
		return true;
	}

private:
	bool judgePoint24(vector<double> &nums, double eps) {
		if (nums.size() == 1) {
			cout << nums[0] << endl;
			return abs(nums[0] - 24.0) <= eps;
		}

		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				double p = nums[i], q = nums[j];
				vector<double> possibles = getResults(p, q, eps);
				nums.erase(nums.begin() + i);
				nums.erase(nums.begin() + j);
				for (auto possible : possibles) {
					nums.push_back(possible);

					if(judgePoint24(nums, eps))  return true;
					nums.pop_back();
				}
				nums.insert(nums.begin() + j, q);
				nums.insert(nums.begin() + i, p);
			}
		}
		return false;
	}

	vector<double> getResults(double p, double q, double eps) {
		vector<double> res = {p + q, p - q, q - p, p * q};
		if (abs(p) > eps)
			res.push_back(q / p);
		if (abs(q) > eps)
			res.push_back(p / q);
		return res;
	}
};

//int main() {
//	vector<int> nums = {4, 1, 8, 7};
//	Solution().judgePoint24(nums);
//}