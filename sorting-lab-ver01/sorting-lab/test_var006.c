/*
  This is a bitonic sort algorithm that only works for powers of 2
  - brycehenderson257@ou.edu

	Original author
  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void swap(float* a, float* b);

int mid(int a, int b);

int separate(float* array, int start, int end);

void quickSort(float* array, int start, int end);

void bitotify(float* vals, int stalsrt, int end, bool isForward);

void rbitotify(float* vals, int start, int end);

void sort(float* vals, int start, int end, bool isForward);

void rsort(float* vals, int start, int end);

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
 	
	int size = (int)pow(2,ceil(log2(m0)));
	float* vals = (float*)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i){
 	 if (i < size-m0){
		vals[i] = INT_MIN;
	 }
	 else {
		vals[i] = x[m0+i-size];
	 }
 	}
	
	bitotify(vals,0,size-1,true);
	for (int i = 0; i < m0; ++i){
		y[i] = vals[i+(size-m0)];
	}
	free(vals);



}

  


//Swap function
void swap(float* a, float* b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

// returns average of two ints rounded down
int mid(int a, int b){
	return (a+b)/2;
}
void bitotify(float* vals, int start, int end, bool isForward ){
	if (end-start < 1){
		return;
	}
	int middle = mid(start,end);
	bitotify(vals, start, middle,true);
	bitotify(vals,middle+1,end,false);
	sort(vals, start, end,isForward);
}



void sort(float* vals, int start, int end,bool isForward){
	int middle = mid(start,end);
	if (end-start <= 1){
		return;
	}
	for (int i = 0; i  <= middle; ++i){
		int a = start+i;
		int b = middle+i;
		if ((vals[a] < vals[b])^(isForward)){
				swap(&vals[a],&vals[b]);
		}
	}
	sort(vals,start, middle,true);
	sort(vals,middle+1,end,false);
}












