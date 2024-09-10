//This is a dispatcher with insertion sort and merge sort with fork

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef COMPUTE_NAME
#endif

#define INSERTION_SORT_THRESHOLD 32

void insertionSort(float arr[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(float arr[], int l, int m, int r, float* L, float* R) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r, float* L, float* R) {
    if (r - l + 1 <= INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, l, r);
        return;
    }

    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, L, R);
		else {
        mergeSort(arr, m + 1, r, L, R);
		}

        merge(arr, l, m, r, L, R);
    }
}

void COMPUTE_NAME(int m0, float* x, float* y) {
    // Copy the contents of the input array into the output array
    int len = 0;
    for (int i0 = 0; i0 < m0; ++i0) {
        y[i0] = x[i0];
        len++;
    }

    // Allocate temp arrays once
    float* L = (float*)malloc((len / 2 + 1) * sizeof(float));
    float* R = (float*)malloc((len / 2 + 1) * sizeof(float));

    // Merge sort
    mergeSort(y, 0, len - 1, L, R);

    // Free temp arrays
    free(L);
    free(R);
}





