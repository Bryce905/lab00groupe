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

// Insertion sort function for small subarrays
void insertionSort(float arr[], int lowBound, int highBound) {
    for (int i = lowBound + 1; i <= highBound; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= lowBound && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(float arr[], int lowBound, int highBound) {
    // Obtain original pivot
    float piv = arr[highBound];
    int temp = lowBound - 1; // This is the right position of pivot

    // Now begin moving elements and changing pivot
    for (int i = lowBound; i <= highBound - 1; i++) {
        if (arr[i] < piv) {
            temp++;
            swap(&arr[temp], &arr[i]);
        }
    }

    swap(&arr[temp + 1], &arr[highBound]);
    return temp + 1;
}

// Quicksort implementation with insertion sort for small subarrays
void quickSort(float arr[], int lowBound, int highBound) {
    while (lowBound < highBound) {
        // Use insertion sort for small subarrays
        if (highBound - lowBound + 1 < INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, lowBound, highBound);
            break;
        } else {
            int partitions = partition(arr, lowBound, highBound);
            
            // Recur on the smaller partition first to optimize tail recursion
            if (partitions - lowBound < highBound - partitions) {
                quickSort(arr, lowBound, partitions - 1);
                lowBound = partitions + 1; // Tail call optimization
            } else {
                quickSort(arr, partitions + 1, highBound);
                highBound = partitions - 1;
            }
        }
    }
}

void COMPUTE_NAME(int m0, float* x, float* y) {
    // Copy the contents of the input array into the output array
    memcpy(y, x, m0 * sizeof(float));

    // Sort the array using quicksort with insertion sort for small subarrays
    quickSort(y, 0, m0 - 1);
}
