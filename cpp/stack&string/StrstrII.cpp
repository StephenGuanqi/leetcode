//
// Created by Guanqi Yu on 1/25/18.
//
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class RollingHash {
public:
	RollingHash(string &s) : vec(s.size()){
		initHash(s);
		for (int i = 0; i < s.size(); ++i) {
			power = (power * 31) %p;
		}
	}

	void append(char c) {
		hash = (hash * BASE + c) % p;
		vec[rear++] = c;
		if (rear == vec.size())
			rear = 0;
	}

	void pop() {
		hash = (hash - vec[rear] * power) % p;
		if (hash < 0)
			hash += p;
	}

	void initHash(string &s) {
		for (string::size_type i = 0; i < s.size(); ++i) {
			append(s[i]);
		}
	}

	long long getHash() const {
		return hash;
	}

	bool operator == (const RollingHash &rh) {
		return equal(vec.begin() + rear, vec.end(), rh.vec.begin())
				&& equal(vec.begin(), vec.begin() + rear, rh.vec.begin() + vec.size() - rear);
	}

	long long power = 1;
	long long p = 1e6; // large prime
	int BASE = 31;
	long long hash = 0;
	vector<char> vec;
	int rear = 0;
};

class Solution {
public:
	/*
	 * @param source: A source string
	 * @param target: A target string
	 * @return: An integer as index
	 */
	int strStr2(const char* source, const char* target) {
		string source_str(source);
		string target_str(target);
		string source_sub = source_str.substr(0, target_str.size());

		RollingHash rhs(source_sub);
		RollingHash rht(target_str);

		if (rhs.getHash() == rht.getHash())
			return 0;
		for (int i = target_str.size(); i < source_str.size(); ++i) {
			rhs.pop();
			rhs.append(source_str[i]);
			if (rhs.getHash() == rht.getHash()) {
				// check collision
				if (rhs == rht)
					return i - target_str.size() + 1;
			}
		}

		return -1;
	}
};

class Solution2 {
public:
	/*
	 * @param source: A source string
	 * @param target: A target string
	 * @return: An integer as index
	 */
	int strStr2(const char* source, const char* target) {
		if (source == nullptr || target == nullptr)
			return -1;
		string source_str(source);
		string target_str(target);

		int m = target_str.size();
		if (m == 0)
			return 0;

		int power = 1;
		for (int i = 0; i < m; ++i) {
			power = (power * BASE) % p;
		}

		int target_code = 0;
		for (int i = 0; i < m; ++i) {
			target_code = (target_code * BASE + target_str[i]) % p;
		}

		int hashCode = 0;
		for (int i = 0; i < source_str.size(); ++i) {
			hashCode = (hashCode * BASE + source_str[i]) % p;
			if (i < m - 1)
				continue;

			if (i >= m) {
				hashCode = hashCode - (source_str[i - m] * power) % p;
				if (hashCode < 0)
					hashCode += BASE;
			}

			if (hashCode == target_code)
				if (source_str.substr(i - m + 1, m) == target_str)
					return i - m + 1;
		}

		return -1;
	}

private:
	int BASE = 31;
	int p = 1e6;
};

//int main() {
//	const char *source = "tartarget";
//	const char *target = "target";
//	Solution().strStr2(source, target);
//}