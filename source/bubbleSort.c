//
// Created by gma on 28-03-26.
//

#include "bubbleSort.h"
#include <stddef.h>

void swap(int *a, int *b);
void swapChar(char *a, char *b);
void swapIntervals(int *a, int *b);

int bubbleSort(int arr[], int n) {
    if (arr == NULL) return -1;
    if (n <= 1) return 0;
    int cpt = 0;
    int swapped = 0;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0 ; j < n-1-i; j++) {
            if (arr[j] > arr[j+1] ) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
                cpt++;
            }

        }
        if (swapped == 0) {
            return cpt;
        }
    }
    return cpt;
}

int bubbleSortChar(char arr[], int n) {
    if (arr == NULL) return -1;
    if (n <= 1) return 0;
    int cpt = 0;
    int swapped = 0;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0 ; j < n-1-i; j++) {
            if (arr[j] > arr[j+1] ) {
                swapChar(&arr[j], &arr[j+1]);
                swapped = 1;
                cpt++;
            }

        }
        if (swapped == 0) {
            return cpt;
        }
    }
    return cpt;
}

int bubbleSortIntervals(int arr[][2], int n) {
    if (arr == NULL) return -1;
    if (n <= 1) return 0;
    int cpt = 0;
    int swapped = 0;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0 ; j < n-1-i; j++) {
            if (arr[j][0] > arr[j+1][0] ) {
                swapIntervals(&arr[j][0], &arr[j+1][0]);
                swapped = 1;
                cpt++;
            }

        }
        if (swapped == 0) {
            return cpt;
        }
    }
    return cpt;
}

void swapChar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapIntervals(int *a, int *b) {
    int tempDeb = *a;          //temp_debut = intervalles[j][0]
    int tempFin = *(a+1);      //temp_fin   = intervalles[j][1]
    *a = *b;                   //intervalles[j][0] = intervalles[j+1][0]
    *(a+1) = *(b+1);           //intervalles[j][1] = intervalles[j+1][1]
    *b = tempDeb;              //intervalles[j+1][0] = temp_debut
    *(b+1)=tempFin;            //intervalles[j+1][1] = temp_fin
}