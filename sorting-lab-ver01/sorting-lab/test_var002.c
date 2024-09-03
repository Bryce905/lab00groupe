/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void swap(float* a, float* b);
int separate(float* array, int start, int end);
void quickSort(float* array, int start, int end);

void COMPUTE_NAME( int m0,
		   float *x,
		   float *y )

{
  /*
    NOTE: This is just a copy of the baseline. You need to modify
    and iterate on this.
  */

  
  /* 
     We need an out-of-place sort (input array != output array)
     so we will do the slowest but easiest thing to get a working
     implementation. First we will copy the contents of the input
     array x into array y, then perform an in-place sort on y.

  */

quicksort(x,0,m0-1);

}

 int separate(float* array, int start, int end) {
	int pivVal = array[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; ++j) {
        	if (array[j] < pivVal) {
            		++i;
            		swap(&array[i], &array[j]);
        	}
    	}
	swap(&array[i + 1], &array[end]);
    	return i + 1;
}


 void quickSort(float* array, int start, int end) {
	if (start < end) {
		int p = separate(array, start, end);
		quickSort(array, start, p-1);
		quickSort(array, p+1, end);
	}
}

  




//Swap function
void swap(float* a, float* b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

