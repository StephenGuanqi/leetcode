//
// Created by Guanqi Yu on 1/4/18.
//
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> hash_map;
		for (auto num : nums1) {
			hash_map[num] += 1;
		}
		for (auto num : nums2) {
			if (hash_map.count(num) && hash_map[num] > 0) {
				hash_map[num] -= 1;
				result.push_back(num);
			}
		}
		return result;
	}
};

class Solution2 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> result;
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				result.push_back(nums1[i]);
				i++;
				j++;
			} else if (nums1[i] > nums2[j])
				j++;
			else
				i++;
		}
		return result;
	}
};