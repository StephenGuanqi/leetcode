//
// Created by Guanqi Yu on 3/3/18.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;



class Solution {
	/**
	 * 3 - (5 - 6) wrong
	 */
public:
	int calculate(string s) {
		if (s.empty())  return 0;
		stack<char> op_stack;
		stack<int> num_stack;
		int number = 0;
		for (int i = 0; i <= s.size(); ++i) {
			char c;
			if (i == s.size())
				c = '+';
			else
				c = s[i];
			if (c == '(' || c == ')' || c == ' ')
				continue;
			else if (isdigit(c)) {
				number = number * 10 + c - '0';
			} else {
				num_stack.push(number);
				number = 0;
				// pop old operator and nums, calc values
				if (!op_stack.empty()) {
					auto op = op_stack.top(); op_stack.pop();
					int num1 = num_stack.top(); num_stack.pop();
					int num2 = num_stack.top(); num_stack.pop();
					if (op == '+')
						num_stack.push(num1 + num2);
					else
						num_stack.push(num2 - num1);
				}
				// push the new operator
				op_stack.push(c);
			}
		}

		return num_stack.top();
	}
};

//int main() {
//	string s = "1 + 1";
//	Solution().calculate(s);
//}