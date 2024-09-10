/*
  This is a bitonic sort with threads
  - brycehenderson257@ou.edu

	Original author
  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <pthread.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

typedef struct{
	float* vals;
	int a;
	int b;
}Swap_args;

typedef struct{
	float* vals;
	int start;
	int end;
}Args;

void* swap(void* args);

void* bitotify(void* args);

void* rbitotify(void* args);

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
	
	Args* fargs;
	//Args* fargs = (Args*)malloc(sizeof(Args));
	fargs->vals = vals;
	fargs->start = 0;
	fargs->end = size-1;

	bitotify((void*)fargs);
	for (int i = 0; i < m0; ++i){
		y[i] = vals[i+(size-m0)];
	}
	free(vals);



}

  


//Swap function
void* swap(void* args){
	Swap_args* sargs = (Swap_args*)(args);
	float* vals = sargs->vals;
	int a = sargs->a;
	int b = sargs->b;
	if (vals[a] > vals[b]){
		float temp = vals[a];
		vals[a] = vals[b];
		vals[b] = temp;
	}
	free(sargs);
}


//perform bitotic sort on array
void* bitotify(void* args){
	Args* targs = (Args*)args;
	float* vals = targs->vals;
	int start = targs->start;
	int end = targs->end;
	free(targs);
	if (end-start < 1){
		return NULL;
	}
	pthread_t bitot, rbitot;
	Args* bargs = (Args*)malloc(sizeof(Args));
	Args* rargs = (Args*)malloc(sizeof(Args));
	bargs->vals = vals;
	bargs->start = start;
	bargs->end = start+((end-start)/2);
	rargs->vals = vals;
	rargs->start = start+((end-start)/2)+1;
	rargs->end = end;
	pthread_create(&bitot,NULL,bitotify,bargs);
	pthread_create(&rbitot,NULL,rbitotify,rargs);
	pthread_join(bitot,NULL);
	pthread_join(rbitot,NULL);
	sort(vals, start, end);
}

void* rbitotify(void* args){
	Args* targs = (Args*)args;
	float* vals = targs->vals;
	int start = targs->start;
	int end = targs->end;
	free(targs);
	if (end-start < 1){
		return NULL;
	}
	pthread_t bitot, rbitot;
	Args* bargs = (Args*)malloc(sizeof(Args));
	Args* rargs = (Args*)malloc(sizeof(Args));
	bargs->vals = vals;
	bargs->start = start;
	bargs->end = start+((end-start)/2);
	rargs->vals = vals;
	rargs->start = start+((end-start)/2)+1;
	rargs->end = end;
	pthread_create(&bitot,NULL,bitotify,bargs);
	pthread_create(&rbitot,NULL,rbitotify,rargs);
	pthread_join(bitot,NULL);
	pthread_join(rbitot,NULL);
	rsort(vals, start, end);
}

//sorts list by putting lowest number at the beginning
void sort(float* vals, int start, int end){
	int num = end - start + 1;
	if (num <= 1){
		return;
	}
	pthread_t threads[num/2];
	for (int i = 0; i  <= (num-1)/2; ++i){
		Swap_args* sargs = (Swap_args*)malloc(sizeof(Swap_args));
		sargs->vals = vals;
		sargs->a = start+i;
		sargs->b = start+i+(num/2);
		pthread_create(&threads[i],NULL,swap,sargs);
		pthread_join(threads[i],NULL);
	}
	sort(vals,start, start+((end-start)/2));
	sort(vals,start+((end-start)/2)+1,end);
}


//sorts list by putting the highest number near the beginning
void rsort(float* vals, int start, int end){
	int num = end - start + 1;
		if (num <= 1){
				return;
		}
		pthread_t threads[num/2];
		for (int i = 0; i  <= (num-1)/2; ++i){
			Swap_args* sargs = (Swap_args*)malloc(sizeof(Swap_args));
			sargs->a = end-i;
			sargs->b = end-i-(num/2);
			sargs->vals = vals;
			pthread_create(&threads[i],NULL,swap,sargs);
			pthread_join(threads[i],NULL);
		}
		rsort(vals,start, start+((end-start)/2));
		rsort(vals,start+((end-start)/2)+1,end);
}