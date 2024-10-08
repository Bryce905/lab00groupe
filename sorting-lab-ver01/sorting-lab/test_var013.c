#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COMPUTE_NAME
#endif

#define INSERTION_SORT_THRESHOLD 32

// Function to swap two elements
void swap(float* a, float* b) {
    float t = *a;
    *a = *b;
    *b = t;
}

int partition(float arr[], int lowBound, int highBound){

	//obtain original pivot
	float piv = arr[highBound];

	int temp = lowBound - 1; //This is the right position of pivot
	//now begin moving elements and changing pivot
	for (int i = lowBound; i <= highBound - 1; i++){
		if(arr[i] < piv) {
			temp++;
			swap(&arr[temp], &arr[i]);
		}
	}

	swap(&arr[temp + 1], &arr[highBound]);
	return temp + 1;

}
//Quicksort implementation
void quickSort(float arr[], int lowBound, int highBound){
	if (lowBound < highBound) {
		int partitions = partition(arr, lowBound, highBound);
		// recursively call to go through entire array
		quickSort(arr, lowBound, partitions -1);
		quickSort(arr, partitions + 1, highBound);
	}

}

void COMPUTE_NAME(int m0, float* x, float* y) {
    // Copy the contents of the input array into the output array
    memcpy(y, x, m0 * sizeof(float));

    // Merge sort
    quickSort(y, 0, m0 -1);
}
