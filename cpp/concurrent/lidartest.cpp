//
// Created by Guanqi Yu on 4/12/18.
//


#include <queue>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
extern "C" {
#include "../lib/csapp.h"
}

#define NELEMENTS 100

using namespace std;

queue<uint64_t> lidarq;
queue<uint64_t> imageq;

void lidar(uint64_t time) {
	lidarq.emplace(time);
}

void image(uint64_t time) {
	imageq.emplace(time);
}

void remove_deprecated(uint64_t time, queue<uint64_t > &q) {
	while (!q.empty() && q.front() < time) {
		q.pop();
	}
}

void fusion() {
	if (imageq.empty() || lidarq.empty()) {
		return;
	}

	remove_deprecated(imageq.front(), lidarq);
	if (lidarq.empty())    return;

	remove_deprecated(lidarq.front(), imageq);
	if (imageq.empty())    return;

	if (imageq.front() != lidarq.front())    return;
	auto top_image = imageq.front();
	auto top_lidar = lidarq.front();
	imageq.pop();
	lidarq.pop();

	// might take a long time
//	process(top_image.second, top_lidar.second);
	cout << "fusion: " << top_image << endl;
}

void *producer_image(void *vargp) {
	auto *array = (uint64_t*)vargp;
	int idx = 0;
	while (true) {
		image(*(array + idx));
		if (++idx == NELEMENTS)
			break;
	}
}

void *producer_lidar(void *vargp) {
	auto *array = (uint64_t*)vargp;
	int idx = 0;
	while (true) {
		lidar(*(array + idx));
		if (++idx == NELEMENTS)
			break;
	}
}

void *consumer_fusion(void *vargp) {
	while (true) {
		fusion();
	}
}

static double uniform() {
	srand(time(0));
	return (double) random() / RAND_MAX;
}

static int randomStep() {
	return (int) ceil(3.0 * uniform());
}

void printInterSection(uint64_t *d1, uint64_t *d2) {
	vector<uint64_t > result;
	unordered_set<uint64_t> hash_set;
	for (int i = 0; i < NELEMENTS; ++i) {
		hash_set.insert(*(d1 + i));
	}
	for (int i = 0; i < NELEMENTS; ++i) {
		uint64_t tmp = *(d2 + i);
		if (hash_set.count(tmp)) {
			result.push_back(tmp);
			hash_set.erase(tmp);
		}
	}
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}

//int main() {
//	// init producer data
//	uint64_t lidar_data[NELEMENTS]; lidar_data[0] = 0;
//	uint64_t image_data[NELEMENTS]; image_data[0] = 0;
//	for (int i = 1; i < NELEMENTS; ++i) {
//		lidar_data[i] = lidar_data[i - 1] + randomStep();
//		image_data[i] = image_data[i - 1] + randomStep();
//	}
//	printInterSection(lidar_data, image_data);
//
//	pthread_t image_ptid;
//	pthread_t lidar_ptid;
//	pthread_t fusion_ptid;
//
//	Pthread_create(&lidar_ptid, NULL, producer_lidar, (void*)lidar_data);
//	Pthread_create(&image_ptid, NULL, producer_image, (void*)image_data);
//	Pthread_create(&fusion_ptid, NULL, consumer_fusion, NULL);
//
//	Pthread_join(image_ptid, NULL);
//	Pthread_join(lidar_ptid, NULL);
//	Pthread_join(fusion_ptid, NULL);
//}













