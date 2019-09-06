//
// Created by Guanqi Yu on 3/20/18.
//



#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		// init
		counts = vector<int>(n);
		indexes = vector<int>(n);
		vector<int> tmpNums(n);
		vector<int> tmpIndexes(n);

		for (int i = 0; i < n; ++i) {
			indexes[i] = i;
		}

		mergeSort(nums, tmpNums, tmpIndexes, 0, n - 1);
		return counts;
	}

private:
	void mergeSort(vector<int>& nums, vector<int> &tmpNums, vector<int> &tmpIndexes,
	               int l, int r) {
		if (l >= r)     return;
		int mid = l + (r - l) / 2;
		mergeSort(nums, tmpNums, tmpIndexes, l, mid);
		mergeSort(nums, tmpNums, tmpIndexes, mid + 1, r);
		mergeSortedArray(nums, tmpNums, tmpIndexes, l, mid, r);
	}

	void mergeSortedArray(vector<int>& nums, vector<int> &tmpNums, vector<int> &tmpIndexes,
	                      int left, int mid, int right) {
		for (int p = left; p <= right; ++p) {
			tmpNums[p] = nums[p];
			tmpIndexes[p] = indexes[p];
		}
		int l = left, r = mid + 1, rightCount = 0;
		for (int p = left; p <= right; ++p) {
			if (r > right || l <= mid && tmpNums[l] <= tmpNums[r]) {
				nums[p] = tmpNums[l];
				indexes[p] = tmpIndexes[l];
				counts[indexes[p]] += rightCount;
				++l;
			} else {
				nums[p] = tmpNums[r];
				indexes[p] = tmpIndexes[r];
				++rightCount;
				++r;
			}
		}
	}

	vector<int> counts;
	vector<int> indexes;
};


struct SegmentNode {
	int sum;
	int start, end;
	SegmentNode *left, *right;
	SegmentNode(int start, int end, int sum): start(start), end(end), sum(sum) {
		left = nullptr;
		right = nullptr;
	}
	~SegmentNode() {
		delete left;
		delete right;
	}
};
class Solution2 {
	/**
	 * Only works when all num in nums are positive numbers
	 * use sum rather than count in segment node so that can tackle with problem of both count and sum
	 */
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		auto root = buildSegmentTree(0, 10000);
		vector<int> ans;
		for (int i = n - 1; i >= 0; --i) {
			int res = 0;
			if (nums[i] > 0)
				res = query(root, 0, nums[i] - 1);
			modify(root, nums[i], 1);
			ans.push_back(res);
		}
		delete root;
		reverse(ans.begin(), ans.end());
		return ans;
	}

private:
	SegmentNode *buildSegmentTree(int start, int end) {
		if (start > end)
			return nullptr;
		auto root = new SegmentNode(start, end, 0);
		if (start == end)
			return root;
		int mid = start + (end - start) / 2;
		root->left = buildSegmentTree(start, mid);
		root->right = buildSegmentTree(mid + 1, end);
		root->sum = root->left->sum + root->right->sum;
		return root;
	}

	int query(SegmentNode *root, int start, int end) {
		if (root->start == start && root->end == end)
			return root->sum;
		int mid = root->start + (root->end - root->start) / 2;
		int leftSum = 0, rightSum = 0;
		if(start <= mid)
			if (end <= mid)
				leftSum = query(root->left, start, end);
			else
				leftSum = query(root->left, start, mid);
		if (mid + 1 <= end)
			if (mid + 1 <= start)
				rightSum = query(root->right, start, end);
			else
				rightSum = query(root->right, mid + 1, end);
		return leftSum + rightSum;
	}

	void modify(SegmentNode *root, int index, int value) {
		int start = root->start, end = root->end;
		if (start == index && end == index) {
			root->sum += value;
			return;
		}
		int mid = start + (end - start) / 2;
		if (index <= mid) {
			modify(root->left, index, value);
		} else {
			modify(root->right, index, value);
		}
		root->sum = root->left->sum + root->right->sum;
	}

};