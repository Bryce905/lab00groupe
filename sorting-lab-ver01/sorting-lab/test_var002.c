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

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void swap(float* a, float* b);

int separate(float* array, int start, int end);

void quickSort(float* array, int start, int end);

void bitotify(float* vals, int stalsrt, int end);

void rbitotify(float* vals, int start, int end);

void sort(float* vals, int start, int end);

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
 	
	

	//bitotify(vals,0,size-1);
	for (int i = 0; i < m0; ++i){
		y[i] = x[i];
	}
	//free(vals);



}

  


//Swap function
void swap(float* a, float* b){
	float temp = *a;
	*a = *b;
	*b = temp;
}


void bitotify(float* vals, int start, int end){
	if (end-start < 1){
		return;
	}
	bitotify(vals, start, start+((end-start)/2));
	rbitotify(vals,start+((end-start)/2)+1,end);
	sort(vals, start, end);
}

void rbitotify(float* vals, int start, int end){
	if(end-start < 1){
		return;
	}
	bitotify(vals, start, start+((end-start)/2));
	rbitotify(vals,start+((end-start)/2)+1,end);
	rsort(vals, start, end);
}

void sort(float* vals, int start, int end){
	int num = end - start + 1;
	if (num <= 1){
		return;
	}
	for (int i = 0; i  <= (num-1)/2; ++i){
		int a = start+i;
		int b = start+i+(num/2);
		if (vals[a] > vals[b]){
				swap(&vals[a],&vals[b]);
		}
	}
	sort(vals,start, start+((end-start)/2));
	sort(vals,start+((end-start)/2)+1,end);
}


void rsort(float* vals, int start, int end){
	int num = end - start + 1;
		if (num <= 1){
				return;
		}
		for (int i = 0; i  <= (num-1)/2; ++i){
			int a = end-i;
			int b = end-i-(num/2);
			if (vals[a] > vals[b]){
				swap(&vals[a],&vals[b]);
			}
		}
		rsort(vals,start, start+((end-start)/2));
		rsort(vals,start+((end-start)/2)+1,end);
}
