/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif
void copyArray(float *x, float *y, int n);
void quickSort(float arr[], int lowBound, int highBound);
void swap(float *a, float *b);
int partition(float arr[], int lowBound, int highBound);
// Function to swap two elements
void swap(float* a, float* b) {
    float t = *a;
    *a = *b;
    *b = t;
}

//Function to copy arrays more efficiently than a for loop
void copyArray(float *x, float *y, int n) {
    float *end = x + n; // Pointer to the end of the array x
    while (x < end) {
        *y = *x; // Copy the value pointed by x to the location pointed by y
        x++;     // Move to the next element in x
        y++;     // Move to the next element in y
    }
}

int partition(float arr[], int lowBound, int highBound){

	//obtain original piv
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
void COMPUTE_NAME( int m0,
		   float *x,
		   float *y )

{
	copyArray(x, y, m0);
	quickSort(y, 0, m0 -1);

}

