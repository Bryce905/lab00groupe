#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COMPUTE_NAME
#endif

#define INSERTION_SORT_THRESHOLD 32
#define MERGE_SORT_THRESHOLD 400
#define QUICK_SORT_THRESHOLD 200

// Insertion sort for small arrays
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
    memcpy(L, &arr[l], n1 * sizeof(float));
    memcpy(R, &arr[m + 1], n2 * sizeof(float));

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
        mergeSort(arr, m + 1, r, L, R);

        merge(arr, l, m, r, L, R);
    }
}
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

    if (m0 < MERGE_SORT_THRESHOLD)
    {
        /* code */
        quickSort(y, 0, m0 - 1);
    } else if (m0 >= MERGE_SORT_THRESHOLD){
        //code
        float* L = (float*)malloc((m0 / 2 + 1) * sizeof(float));
        float* R = (float*)malloc((m0 / 2 + 1) * sizeof(float));
        // Merge sort
        mergeSort(y, 0, m0 - 1, L, R);

        // Free temp arrays
        free(L);
        free(R);
    }
    
}
