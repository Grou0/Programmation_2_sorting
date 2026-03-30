//
// Created by gma on 29-03-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "quickSort.h"

// Vérifie si trié
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

// Compare deux tableaux
bool arraysEqual(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Copie tableau
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

// Affichage debug
void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

// Référence avec qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void referenceSort(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}

// Test principal
void runTest(const char *name, int input[], int n) {
    int result;

    // Cas invalide
    if (input == NULL) {
        result = quickSort(NULL, 0, 0);
        if (result != -1) {
            printf("NOK %s FAILED: expected error (1)\n", name);
        } else {
            printf("OK %s PASSED (NULL handled)\n", name);
        }
        return;
    }

    int testArr[n];
    int expected[n];

    copyArray(input, testArr, n);
    copyArray(input, expected, n);

    referenceSort(expected, n);

    result = quickSort(testArr, 0, n - 1);

    if (result != 0) {
        printf("NOK %s FAILED: return = %d (expected 0)\n", name, result);
        return;
    }

    if (!isSorted(testArr, n)) {
        printf("NOK %s FAILED: not sorted\n", name);
        printArray(testArr, n);
        printf("\n");
        return;
    }

    if (!arraysEqual(testArr, expected, n)) {
        printf("NOK %s FAILED: incorrect result\n", name);
        printf("Expected: ");
        printArray(expected, n);
        printf("\nGot: ");
        printArray(testArr, n);
        printf("\n");
        return;
    }

    printf("OK %s PASSED\n", name);
}

int main() {
    int t1[] = {5, 3, 8, 4, 2};
    runTest("Random array", t1, 5);

    int t2[] = {1, 2, 3, 4, 5};
    runTest("Already sorted", t2, 5);

    int t3[] = {5, 4, 3, 2, 1};
    runTest("Reverse sorted", t3, 5);

    int t4[] = {1};
    runTest("Single element", t4, 1);

    int t5[] = {4, 2, 5, 2, 3, 4};
    runTest("Duplicates", t5, 6);

    int t6[] = {-3, -1, -7, 2, 0};
    runTest("Negative numbers", t6, 5);

    int t7[] = {100, -100, 50, -50, 0};
    runTest("Mixed values", t7, 5);

    // Cas NULL
    runTest("NULL array", NULL, 0);

    return 0;
}