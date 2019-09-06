//
// Created by Guanqi Yu on 1/29/18.
//

#include <vector>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

class SegmentTreeNode {
public:
	int start, end, max;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int max) :
			start(start), end(end), max(max) {
		left = nullptr;
		right = nullptr;
	}
};

class SegTree {
public:
	/*
	 * @param root: The root of segment tree.
	 * @param start: start value.
	 * @param end: end value.
	 * @return: The maximum number in the interval [start, end]
	 */
	int query(SegmentTreeNode * root, int start, int end) {
		if (root->start == start && root->end == end)
			return root->max;

		int mid = root->start + (root->end - root->start) / 2;
		int leftmax = INT_MIN, rightmax = INT_MIN;
		// left interval
		if (start <= mid)
			if (end <= mid) // contains
				leftmax = query(root->left, start, end);
			else // split
				leftmax = query(root->left, start, mid);
		// right interval
		if (mid < end)
			if (mid < start) // contains
				rightmax = query(root->right, start, end);
			else // split
				rightmax = query(root->right, mid + 1, end);
		return max(leftmax, rightmax);
	}

	SegmentTreeNode *buildTree(vector<int> &A, int start, int end) {
		if (start > end)   return nullptr;
		auto root = new SegmentTreeNode(start, end, A[start]);
		if (start == end)
			return root;
		int mid = start + (end - start) / 2;
		root->left = buildTree(A, start, mid);
		root->right = buildTree(A, mid + 1, end);
		root->max = max(root->left->max, root->right->max);
		return root;
	}

	void modify(SegmentTreeNode * root, int index, int value) {
		if (root->start == index && root->end == index) {
			root->max = value;
			return;
		}
		int mid = root->start + (root->end - root->start) / 2;
		if (index <= mid)
			modify(root->left, index, value);
		else
			modify(root->right, index, value);
		root->max = max(root->left->max, root->right->max);
	}

	string serializeTree(SegmentTreeNode *root) {
		queue<SegmentTreeNode*> q;
		if (root == nullptr)
			return "";
		ostringstream oss;
		q.push(root);
		while (!q.empty()) {
			auto node = q.front(); q.pop();
			if (node == nullptr)
				continue;
			oss << "[" << node->start << "," << node->end << "," << node->max << "]";
			SegmentTreeNode *l = node->left;
			SegmentTreeNode *r = node->right;
			q.push(l);
			q.push(r);
		}
		return oss.str();
	}
};

//int main() {
//	vector<int> A = {2, 1, 0, 3};
//	SegTree st;
//	SegmentTreeNode *root = st.buildTree(A, 0, A.size() - 1);
//	cout << st.serializeTree(root) << endl;
//	st.modify(root, 1, 4);
//	cout << st.serializeTree(root) << endl;
//}