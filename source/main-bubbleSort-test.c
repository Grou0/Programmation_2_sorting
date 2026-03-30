#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bubbleSort.h"

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

bool arraysEqual(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]");
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void referenceSort(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}

void runTest(const char *testName, int input[], int n) {
    int result;

    if (n == 0) {
        result = bubbleSort(NULL, 0);
        if (result != -1) {
            printf("❌ %s FAILED: expected -1 for NULL array\n", testName);
        } else {
            printf("✅ %s PASSED (NULL handled)\n", testName);
        }
        return;
    }

    int testArr[n];
    int expected[n];

    copyArray(input, testArr, n);
    copyArray(input, expected, n);

    referenceSort(expected, n);

    result = bubbleSort(testArr, n);

    if (result != 0) {
        printf("❌ %s FAILED: return value = %d (expected 0)\n", testName, result);
        return;
    }

    if (!isSorted(testArr, n)) {
        printf("❌ %s FAILED: array not sorted\n", testName);
        printArray(testArr, n);
        printf("\n");
        return;
    }

    if (!arraysEqual(testArr, expected, n)) {
        printf("❌ %s FAILED: incorrect sorting\n", testName);
        printf("Expected: ");
        printArray(expected, n);
        printf("\nGot: ");
        printArray(testArr, n);
        printf("\n");
        return;
    }

    printf("✅ %s PASSED\n", testName);
}

int main() {
    int test1[] = {5, 3, 8, 4, 2};
    runTest("Random array", test1, 5);

    int test2[] = {1, 2, 3, 4, 5};
    runTest("Already sorted", test2, 5);

    int test3[] = {5, 4, 3, 2, 1};
    runTest("Reverse sorted", test3, 5);

    int test4[] = {1};
    runTest("Single element", test4, 1);

    int test5[] = {4, 2, 5, 2, 3, 4};
    runTest("Duplicates", test5, 6);

    int test6[] = {-3, -1, -7, 2, 0};
    runTest("Negative numbers", test6, 5);

    int test7[] = {100, -100, 50, -50, 0};
    runTest("Mixed values", test7, 5);

    // Test NULL explicite
    runTest("NULL array", NULL, 0);

    return 0;
}