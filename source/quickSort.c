//
// Created by gma on 28-03-26.
//

#include "quickSort.h"
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high, int* cpt) ;
void swapping(int *a, int *b) ;
int bigger(int arr[] ,int a ,int b);

//     ** Choix du pivot **
// mode 1 : dernier élément (choix par defaut)
// mode 2 : pivot aléatoire
// mode 3 : médiane de trois

int quickSort(int arr[], int low, int high , int mode) {
    if (arr == NULL) return -1;
    int cpt = 0;

    if (low < high) {
        if(mode == MEDIAN) {
            int mid = low + (high-low)/2;
            int pivot_index = low;
            int iBiggest = bigger(arr, low, bigger(arr, mid, high));
            if (iBiggest == low) {
                pivot_index = bigger(arr, mid, high) ;
            }else if (iBiggest == mid) {
                pivot_index = bigger(arr, low, high) ;
            }else {
                pivot_index = bigger(arr, low, mid) ;
            }
            swapping(&arr[pivot_index], &arr[high]);
        }else if(mode == RANDOM) {
            int pivot_index = low + rand() % (high - low + 1);
            swapping(&arr[pivot_index], &arr[high]);
        }
        int pivot = partition(arr, low, high, &cpt);
        int left = quickSort(arr, low, pivot-1, mode);
        int right = quickSort(arr, pivot+1 , high, mode);
        return left + right + cpt ;
    }else{
        return 0 ;
    }
}

int partition(int arr[], int low, int high, int* cpt) {
    int pivot = arr[high];
    int index = low - 1 ;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            index++;
            swapping(&arr[j], &arr[index]);
        }
        (*cpt)++;
    }
    swapping(&arr[index + 1], &arr[high]);
    return index+1 ;
}

void swapping(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bigger(int arr[],int a,int b) {
    if (arr[a] > arr[b]) return a;
    return b;
}