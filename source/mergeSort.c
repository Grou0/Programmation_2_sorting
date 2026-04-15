//
// Created by gma on 13-04-26.
//
#include "mergeSort.h"

void merge(int tab[], int debut, int mid, int fin);

void mergeSort(int tab[], int debut, int fin) {
    if (debut < fin) {
        int mid = (debut+fin)/2;
        mergeSort(tab, debut, mid);
        mergeSort(tab, mid+1, fin);
        merge(tab, debut, mid, fin);
    }
}

void merge(int tab[], int debut, int mid, int fin) {
    //int temp[fin - debut + 1];
    // int *temp = malloc((fin - debut + 1) * sizeof(int));
    int i = 0;
    int j = 0;
    int k = debut ;

    int n1 = mid - debut + 1;
    int n2 = fin - mid;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = tab[debut + i];
    for (j = 0; j < n2; j++)
        R[j] = tab[mid + 1 + j];

    i = 0 ; j = 0 ;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }else{
            tab[k] = R[j];
            j++;
        }
        k++;
    }while (i < n1) {
        tab[k] = L[i];
        k++;
        i++;
    }while (j < n2) {
        tab[k] = R[j];
        k++;
        j++;
    }
}
