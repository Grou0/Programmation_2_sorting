//
// Created by gma on 28-03-26.
//

#include "bubbleSort.h"
#include <stddef.h>

void swap(int *a, int *b);

int bubbleSort(int arr[], int n) {
    if (arr == NULL) return -1;
    if (n <= 1) return 0;
    int swapped = 0;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0 ; j < n-1-i; j++) {
            if (arr[j] > arr[j+1] ) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }

        }
        if (swapped == 0) {
            return 0;
        }
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}