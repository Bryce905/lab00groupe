/*
  This is a simple implementation of an unoptimized sort.

  - richard.m.veras@ou.edu

*/


#include <stdio.h>
#include <stdlib.h>

#ifndef COMPUTE_NAME
#define COMPUTE_NAME baseline
#endif

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


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

  // copy the contents of the input array into the output array
  int len = 0;
  for( int i0 = 0; i0 < m0; ++i0 )
    {
      y[i0] = x[i0];
      len++;
    }
  

  // merge sort

  mergeSort(y,0,len);

}