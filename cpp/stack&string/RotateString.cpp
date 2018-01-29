//
// Created by Guanqi Yu on 1/23/18.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>

/**
 *
 * Traverse Order:   traverse vs divide conquer vs non-recursive
 * divide conquer  ---->   check the meaning of the subroutine
 * traversal, parameter has the return result
 */
using namespace std;

class Solution {
public:
	/*
	 * @param str: An array of char
	 * @param offset: An integer
	 * @return: nothing
	 */
	void rotateString(string &str, int offset) {
		if (str.empty())    return;
		offset = offset % str.size();
		reverse(str, 0, str.size() - offset - 1);
		reverse(str, str.size() - offset, str.size() - 1);
		reverse(str, 0, str.size() - 1);
	}

	void reverse(string &str, int start, int end) {
		while (start <= end) {
			swap(str[start], str[end]);
			start++;
			end--;
		}
	}

};