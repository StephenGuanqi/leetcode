//
// Created by Guanqi Yu on 3/8/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;



//int main() {
//	int N, K = 0;
//	cin.clear();
//	int num = 0;
//	string line = "";
//	while (getline(cin, line)) {
//		istringstream iss(line);
//		vector<int> A;
//		iss >> K;
//		while (iss >> num) {
//			A.push_back(num);
//		}
//
//		ostream_iterator<int> oi(cout, " ");
//		copy(A.begin(), A.end(), oi);
//		cout << endl;
//
//		auto cmp = [&A] (pair<int, int> &p1, pair<int, int> &p2) {
//			return A[p1.first] * A[p2.second] > A[p2.first] * A[p1.second];
//		};
//		int n = A.size();
//		vector<vector<bool>> visited(n, vector<bool>(n));
//		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // min heap {index1, index2}
//		// two pointer
//		pq.push({0, n - 1});
//		visited[0][n - 1] = true;
//		int pi = 0, qi = 0;
//		while(K-- > 0) {
//			auto minp = pq.top(); pq.pop();
//			pi = minp.first;
//			qi = minp.second;
//			if (pi + 1 < qi) {
//				if (!visited[pi + 1][qi]) {
//					pq.push({pi + 1, qi});
//					visited[pi + 1][qi] = true;
//				}
//				if (!visited[pi][qi + 1]) {
//					pq.push({pi, qi + 1});
//					visited[pi][qi + 1] = true;
//				}
//			}
//		}
//		cout << A[pi] << " " << A[qi] << endl;
//
//	}
//
//	return 0;
//}