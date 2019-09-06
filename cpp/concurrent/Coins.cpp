//
// Created by Guanqi Yu on 4/14/18.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


//int main(){
//	//freopen("1.in","r",stdin);
//	int n1, n2, m = 0;
//	cin >> n1 >> n2 >> m;
//	vector<int> coins(n1);
//	vector<int> memos(n2);
//	for (int i = 0; i < n1; ++i) {
//		cin >> coins[i];
//	}
//	for (int i = 0; i < n2; ++i) {
//		cin >> memos[i];
//	}
//
//	vector<vector<int>> f1(n1 + 1, vector<int>(m + 1));
//	vector<vector<int>> f2(n2 + 1, vector<int>(m + 1));
//
//	for (int i = 0; i <= n1; ++i) {
//		f1[i][0] = 1;
//	}
//	for (int i = 1; i <= n1; ++i) {
//		for (int s = 1; s <= m; ++s) {
//			f1[i][s] = f1[i - 1][s] + (s >= coins[i - 1] ? f1[i][s - coins[i - 1]] : 0);
//		}
//	}
//	// f1[n1][:]
//	for (auto num : f1[n1]) {
//		cout << num << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i <= n2; ++i) {
//		f2[i][0] = 1;
//	}
//
//	for (int i = 1; i <= n2; ++i) {
//		for (int s = 1; s <= m; ++s) {
//			f2[i][s] = f2[i - 1][s] + (s >= memos[i - 1] ? f2[i - 1][s - memos[i - 1]] : 0);
//		}
//	}
//	// f2[n2][:]
//	for (auto num : f2[n2]) {
//		cout << num << " ";
//	}
//	cout << endl;
//
//	int ans = 0;
//	for (int l = 0; l <= m; ++l) {
//		int r = m - l;
//		if (f1[n1][l] > 0 && f2[n2][r] > 0) {
//			ans += f1[n1][l] * f2[n2][r];
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}