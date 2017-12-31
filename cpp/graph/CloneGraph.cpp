#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	    int label;
	     vector<UndirectedGraphNode *> neighbors;
	     UndirectedGraphNode(int x) : label(x) {};
	 };

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)    return nullptr;
		auto node_set = getAllNodes(node);
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
		for (auto node : node_set) {
			UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
			mapping[node] = newNode;
		}
		for (auto node : node_set) {
			auto newNode = mapping[node];
			for (auto nei : node->neighbors) {
				(newNode->neighbors).push_back(mapping[nei]);
			}
		}
		return mapping[node];
	}

private:
	unordered_set<UndirectedGraphNode*> getAllNodes(UndirectedGraphNode *node) {
		queue<UndirectedGraphNode*> q;
		unordered_set<UndirectedGraphNode*> hash_set;
		q.push(node);
		hash_set.insert(node);
		while (q.size() != 0) {
			auto node = q.front(); q.pop();
			for (auto nei : node->neighbors) {
				if (hash_set.find(nei) == hash_set.cend()) {
					q.push(nei);
					hash_set.insert(nei);
				}
			}
		}
		return hash_set;
	}
};

class Solution2 {
public:
	/**
	*  Or we can just use the mapping as a hash_set
	less readable
	*/
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)    return nullptr;
		map[node] = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> q;
		q.push(node);
		while(!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto nei : cur->neighbors) {
				// no copy of nei yet
				if (map.find(nei) == map.cend()) {
					map[nei] = new UndirectedGraphNode(nei->label);
					q.push(nei);
				}
				// has copy of nei
				map[cur]->neighbors.push_back(map[nei]);
			}
		}
		return map[node];
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
};