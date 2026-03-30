//
// Created by gma on 28-03-26.
//

#include "quickSort.h"
#include <stddef.h>


int partition(int arr[], int low, int high) ;
void swapping(int *a , int *b) ;


int quickSort(int arr[], int low, int high) {
    if (arr == NULL) return -1;

    if (low < high) {
        int pivot = partition(arr, low, high);

        int tp = quickSort(arr, low, pivot-1);
        tp = quickSort(arr, pivot+1 , high);

    }else {
        return 0 ;
    }

}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int index = low - 1 ;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            index++;
            swapping(&arr[j], &arr[index]);
        }
    }
    swapping(&arr[index + 1], &arr[high]);
    return index+1 ;
}

void swapping(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}