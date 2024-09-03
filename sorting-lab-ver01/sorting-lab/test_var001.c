/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

float* findMin(float* vals,int start, int end);
void swap(float* a, float* b);

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

 for (int i= 0; i < m0; ++i){
  y[i] = x[i];
 }

 for (int i = 0; i < m0-1; ++i) {
		float* min = findMin(y,i,m0);
		if (*min != x[i]){
			swap(&y[i],min);
		}
	}



}


//Swap function
void swap(float* a, float* b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

float* findMin(float* vals,int start, int end){
	float* min = &vals[start];
	for (int i=start+1; i < end; ++i){
		if (vals[i] < *min) {
			min = &vals[i];
		}
	}
	return min;
}
