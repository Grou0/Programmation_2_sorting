//
// Created by gma on 13-04-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergeSort.h"

int main() {

    int arr[] = {38, 27, 43, 10 , 5, 2, 50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}