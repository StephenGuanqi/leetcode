//
// Created by Guanqi Yu on 3/12/18.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class HashHeap {

public:
	HashHeap(vector<pair<int, int>> dists) {
		dists_ = dists;
		build_heap();
	}

	inline int left(int index)
	{
		return (index << 1) + 1;
	}

	inline int right(int index)
	{
		return (index << 1) + 2;
	}

	inline int parent(int index)
	{
		return index == 0? -1 : (index - 1) >> 1;
	}

	void build_heap()
	{
		for (int i = (dists_.size() >> 1) - 1; i >= 0; i--) {
			min_heapify(i, dists_.size() - 1);
		}
		for (int i = 0; i < dists_.size(); ++i) {
			map[dists_[i].first] = i;
		}
	}

	void print() {
		for (auto dist : dists_) {
			cout << dist.first << " " << dist.second << ",";
		}
		cout << endl;
	}

	void min_heapify(int index, int end)
	{
		int l = left(index), r = right(index);
		int smallest = index;
		if (l <= end && dists_[l].second < dists_[smallest].second)    smallest = l;
		if (r <= end && dists_[r].second < dists_[smallest].second)    smallest = r;

		if (smallest != index)
		{
			// update index
			int key1 = dists_[index].first, key2 = dists_[smallest].first;
			map[key1] = smallest;
			map[key2] = index;
			// swap and heapify
			swap(dists_[smallest], dists_[index]);
			min_heapify(smallest, end);
		}
	}

	pair<int, int> &top() {
		return dists_.front();
	}

	void pop() {
		// update index
		map.erase(dists_.front().first);
		map[dists_.back().first] = 0;
		// swap and heapify
		swap(dists_.front(), dists_.back());
		dists_.pop_back();
		min_heapify(0, dists_.size() - 1);
	}

	void update(int key, int value) {
		auto &p = dists_[map[key]];
		if (p.second < value) {
			p.second = value;
			min_heapify(map[key], dists_.size() - 1);
		} else {
			p.second = value;
			popUp(map[key]);
		}
	}

	int getNode(int key) {
		return dists_[map[key]].second;
	}

	void popUp(int index) {
		while (parent(index) > -1) {
			int pid = parent(index);
			if (dists_[pid].second > dists_[index].second) {
				// update index
				int key1 = dists_[index].first, key2 = dists_[pid].first;
				map[key1] = pid;
				map[key2] = index;
				// swap and popup
				swap(dists_[pid], dists_[index]);
				index = pid;
			} else {
				break;
			}
		}
	}

	bool empty() {
		return dists_.size() == 0;
	}

private:
	vector<pair<int, int>> dists_;
	unordered_map<int, int> map; // {key, pos in vec}
};

class Graph {
public:
	Graph() = default;

	void addEdges(int n1, int n2, int w) {
		G_[n1][n2] = w;
		nodes_.insert(n1);
		nodes_.insert(n2);
	}

	// Time Complexity O((V+E)V)
	// Could use hash heap to reduce time complexity to O((V+E)lgV)_
	int calcMinDist(int n1, int n2) {
		vector<pair<int, int>> dist; // use vector as prioryty queue
		for (auto node : nodes_) {
			if (node == n1) {
				dist.push_back({node, 0}); // {key, value}
			} else {
				dist.push_back({node, INT_MAX});
			}
		}

		auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {
			return p1.second > p2.second;
		};
		make_heap(dist.begin(), dist.end(), cmp); // min heap

		while (dist.size() != 0) {
			// pop min dist node from the queue
			auto minn = dist.front();
			if (minn.first == n2) {
				return  minn.second;
			}

			// cout << minn.first << " " << minn.second << endl;
			pop_heap(dist.begin(), dist.end(), cmp);
			dist.pop_back();



			// update adjacent neighbours
			int node = minn.first;
			for (auto elem : G_[node]) {
				int neigh = elem.first;
				int weight = elem.second;

				// update neigh dist in the pq
				unsigned pos = 0;
				for (pos = 0; pos < dist.size(); ++pos) {
					auto &p = dist[pos];
					if (p.first == neigh) {
						p.second = min(p.second, minn.second + weight);
					}
				}

				make_heap(dist.begin(), dist.end(), cmp);

			}
		}
		return INT_MAX;
	}

	int calcMinDist2(int n1, int n2) {
		vector<pair<int, int>> dist; // use vector as prioryty queue
		for (auto node : nodes_) {
			if (node == n1) {
				dist.push_back({node, 0}); // {key, value}
			} else {
				dist.push_back({node, INT_MAX});
			}
		}

		HashHeap hh(dist);

		while (!hh.empty()) {
			// pop min dist node from the queue
			auto minn = hh.top();
			if (minn.first == n2) {
				return  minn.second;
			}

			hh.pop();

			// update adjacent neighbours
			int node = minn.first;
			for (auto elem : G_[node]) {
				int neigh = elem.first;
				int weight = elem.second;

				// update neigh dist in the pq
				int w = hh.getNode(neigh);
				if (w > minn.second + weight)
					hh.update(neigh, minn.second + weight);

			}
		}
		return INT_MAX;
	}

private:

	unordered_map<int, unordered_map<int, int>> G_;
	unordered_set<int> nodes_;
};


//int main() {
//	vector<pair<int, int>> vec = {{1, 4}, {2, 5}, {3, 3}, {4, 2}, {5, 1}};
//	HashHeap hh(vec);
//	hh.print();
////	hh.pop();
////	hh.print();
////	hh.pop();
////	hh.print();
//	hh.update(1, 0);
//	hh.print();
//}