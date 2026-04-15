//
// Created by gma on 15-04-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapSort.h"

int main() {

    int arr[] = {38, 27, 43, 10 , 5, 2, 50, 1, 15, 15, 105, -5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int cpt = heapSort(arr, arr_size);
    printf("cpt  heapSort : %d\n", cpt);
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}