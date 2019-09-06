//
// Created by Guanqi Yu on 5/2/18.
//


#include <queue>
#include <iostream>
#include <cmath>
extern "C" {
#include "../lib/csapp.h"
}

using namespace std;

typedef struct {
	unsigned char *image;
	float *kernel;
	volatile unsigned char *out;
	int image_width;
	int image_height;
	int kernel_size;
	int start;
	int end;
} args;

void *sub_convolve(void *vargs) {
	args *a = (args*)vargs;
	int start = a->start;
	int end = a->end;
	int kernel_size = a->kernel_size;
	int image_height = a->image_height;
	int image_width = a->image_width;
	unsigned char *image = a->image;
	float *kernel = a->kernel;
	volatile unsigned char *out = a->out;

	// TODO copy the input image into the stack to avoid access same element from DRAM multiple times (specifically kernel_size * kernel_size times)

	// k is the index range of output image that this thread is responsible for calculating
	for (int k = start; k <= end; ++k) {

		// extract i and j as the row and col index as k
		int i = k / image_width;
		int j = k % image_width;

		// local cache
		float sum = 0;
		// traverse the kernel square to calculate value for position k
		for(int m = 0; m < kernel_size; ++m) {
			// row index of flipped kernel
			int mm = kernel_size - 1 - m;
			for(int n = 0; n < kernel_size; ++n) {
				// column index of flipped kernel
				int nn = kernel_size - 1 - n;

				// index of input image, used for checking boundary
				int rowIndex = i + m - kernel_size / 2;
				int colIndex = j + n - kernel_size / 2;

				// ignore input samples which are out of bound, which makes 0 padding for the output at edge
				if(rowIndex >= 0 && rowIndex < image_height && colIndex >= 0 && colIndex < image_width)
					sum += image[image_width * rowIndex + colIndex] * kernel[kernel_size * mm + nn];
			}
		}

		out[k] = (unsigned char)(fabs(sum));
	}
}

/**
 * out and image has the same dimension, same convolve use 0 padding
 *
 * @param image
 * @param width
 * @param height
 * @param num_thread
 * @param kernel
 * @param kernel_size
 */
void convolve(unsigned char * image, unsigned char *out,
             int width=256, int height =256, int num_thread, float *kernel, int kernel_size = 3)
{
	if (!image || !kernel)  return;
	if (kernel_size > width || kernel_size > height) {
		printf("invalid kernel size!");
		return;
	}

	// divide task, number of output per thread
	// e.g. input is 16 * 16, num_thread is 10
	// we create 11 threads, with first 10 thread each handle 25 element, the 11th handle 6 element
	int num_task_per_thread = width * height / num_thread;

	// TODO better strategy for allocating number of elements to each thread, according to the size of cache block

	args arg_array[num_thread + 1];
	for (int i = 0; i <= num_thread; ++i) {
		arg_array[i].image_width = width;
		arg_array[i].image_height = height;
		arg_array[i].kernel_size = kernel_size;
		arg_array[i].image = image;
		arg_array[i].kernel = kernel;
		arg_array[i].out = out;
		arg_array[i].start = i * num_task_per_thread;
		arg_array[i].end = i == num_thread ? width * height - 1
		                   : (i + 1) * num_task_per_thread - 1;
	}

	pthread_t tid[num_thread + 1];
	for (int i = 0; i <= num_thread; ++i) {
		// all capital function below is a wrapper of the original API with unix error handling
		Pthread_create(&tid[i], NULL, sub_convolve, &arg_array[i]);
	}

	for (int i = 0; i <= num_thread; ++i) {
		Pthread_join(tid[i], NULL);
	}
}
