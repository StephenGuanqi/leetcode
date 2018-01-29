//
// Created by Guanqi Yu on 1/9/18.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

class Record {
public:
   int id, score;
   Record(int id, int score) {
	    this->id = id;
	     this->score = score;
   }
};

class Solution {
	/**
	 * notice the reference!!
	 * don't call copy constructor unless you want to!!!
	 */
public:
	/**
	 * @param results a list of <student_id, score>
	 * @return find the average of 5 highest scores for each person
	 * map<int, double> (student_id, average_score)
	 */
	map<int, double> highFive(vector<Record>& results) {
		// {record.id, min_heap<record.score>}
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hash;
		for (auto record : results) {
			auto &q = hash[record.id];
			if (q.size() < 5) {
				q.push(record.score);
			} else if (q.top() < record.score){
				q.pop();
				q.push(record.score);
			}
		}
		map<int, double> ans;
		for (auto entry : hash) {
			ans[entry.first] = calcAvg(entry.second);
		}
		return ans;
	}

private:
	double calcAvg(priority_queue<int,vector<int>,greater<int>> &q) {
		double sum = 0;
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			sum += (double)q.top();
			q.pop();
		}
		return sum / sz;
	}
};


//int main() {
//	vector<Record> results = { {1, 91}, {1, 92}, {2, 93}, {2, 99}, {2, 98}, {2, 97},
//	                           {1, 60}, {1, 58}, {2, 100}, {1, 61}};
//	Solution().highFive(results);
//}