//
// Created by Guanqi Yu on 1/10/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;


class MovingAverage {
public:
	/*
	* @param size: An integer
	*/MovingAverage(int size) : psum(size + 1, 0){
		this->size = size;
		id = 0;
		psum[0] = 0;
	}

	/*
	 * @param val: An integer
	 * @return:
	 */
	double next(int val) {
		++id;
		psum[mod(id)] = psum[mod(id - 1)] + val;
		if (id - size >= 0)
			return (psum[mod(id)] - psum[mod(id - size)]) / size;
		else
			return psum[id] / id;
	}

private:
	inline int mod(int index) {
		return index % (size + 1);
	}

	vector<double> psum; // prefix sum array
	int id;
	int size;
};
