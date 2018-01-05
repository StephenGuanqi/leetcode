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
	 * @param colors: A list of integer
	 * @param k: An integer
	 * @return: nothing
	 */
	void sortColors2(vector<int> &colors, int k) {
		if (k == 1) return;
		sort(colors, 0, colors.size() - 1, 1, k);
	}

private:
	void sort(vector<int> &colors, int start, int end, int beginK, int endK) {
		if (beginK == endK) return;
		int midK = beginK + (endK - beginK) / 2;
		int pos = partition(colors, start, end, midK); // index of first elem > k
		sort(colors, start, pos - 1, beginK, midK);
		sort(colors, pos, end, midK + 1, endK);
	}

	int partition(vector<int> &colors, int start, int end, int k) {
		int i = start, j = end;
		while (i <= j) {
			while (i <= j && colors[i] <= k) ++i;
			while (i <= j && colors[j] > k) --j;
			if (i <= j) {
				swap(colors[i++], colors[j--]);
			}
		}
		return i;
	}

};