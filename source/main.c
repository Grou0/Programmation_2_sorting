//
// Created by gma on 02-05-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "quickSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include <time.h>


#define BENCHMARK_SIZE 50000
void benchmarkingSortingAlgortims();
int anagramsSearch(char *chain1, char *chain2);
int doublonsSearch(int* tab, int n) ;
int twoClosest(int* tab, int n);

int main() {
    //chain1[] c'est différent que *chain1
    char chain1[] = "aube";
    char chain2[] = "beau";
    int tab[] = {99,88,77,55,50,44,33,22,10,0};
    int n =10;

    int result = doublonsSearch(tab, n) ;
    printf("result = %d\n", result);

    int res = twoClosest(tab, n) ;
    printf("Indice 1 = %d\n", tab[res-1]);
    printf("Indice 2 = %d\n", tab[res]);
    printf("Diff : %d\n",(tab[res]-tab[res-1]));


    return 0;
}

int twoClosest(int* tab, int n) {
    if (tab== 0) {
        printf("No tab found.\n");
        return -1;
    }
    if (n<=0) {
        printf("Size smaller or equal  0.\n");
        return -1;
    }
    int res = bubbleSort(tab, n);
    if (res < 0) {
        printf("Error during bubblesort.\n");
        return -1;
    }
    int min = abs(tab[0] - tab[1]);
    int indice0 = 0 ;
    int indice1 = 1 ;
    for (int i = 2 ; i < n ; i++) {
        if (tab[i]-tab[i-1] < min) {
            min = tab[i]-tab[i-1];
            indice0 = i-1;
            indice1 = i;
        }
    }
    return indice1 ;


}

int doublonsSearch(int* tab, int n) {
    if (tab == 0) {
        printf("Tab is null.\n");
        return -1;
    }
    if (n <= 0) {
        printf("Size smaller or equal  0.\n");
        return -1;
    }
    int res = bubbleSort(tab, n);
    if (res < 0) {
        printf("Error during bubblesort.\n");
        return -1;
    }
    int temp = tab[0];
    for (int i = 1 ; i < n ; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
        if ( tab[i] == temp ) {
            printf("Tab contains doublons.\n");
            return 1;
        }
        temp = tab[i];
    }
    printf("Tab does not contains doublons.\n");
    return 0;

}

//In C, writing the name of an array without square brackets is equivalent to writing the address of the array’s first element.

int anagramsSearch(char* chain1, char* chain2) {
    int len1 = strlen(chain1);
    int len2 = strlen(chain2);
    if (len2 != len1) {
        printf("Not the same length, not an annagram.\n");
        return 0;
    }
    const char *ptr1 = chain1;
    int i = 0 ;

    if (bubbleSortChar(chain1, len1) < 0 || bubbleSortChar(chain2, len2) < 0) {
        printf("Error during bubblesort.\n");
        return -1;
    }

    printf("Len chain 1 = %d\n",len1);

    while (*ptr1 != '\0') {
        printf("chain %d = %c\n",i, chain1[i]);
        if (chain1[i] != chain2[i]) {
            printf("Not an annagram.\n");
            return 0;
        }
        i++;
        ptr1++;
    }
    printf("This is an annagram.\n");
    return 1;
}


void benchmarkingSortingAlgortims() {
        //For time calculation
    clock_t start, end;
    double cpu_time_used;


    srand(time(NULL));
    int r = rand();

    int cpt = 0 ;

    //allocation et création du tablea
    int* tab_original = malloc(BENCHMARK_SIZE * sizeof(int));
    int* tab_copie = malloc(BENCHMARK_SIZE * sizeof(int));

   for (int i = 0; i < BENCHMARK_SIZE; i++) {
        tab_original[i] = rand();;
   }
// ***************************************************************************************

    printf("\nHeapSort() starts \n");

    // arr[] = {38, 27, 43, 10 , 5, 2, 50, 1, 15, 15, 105, -5, -10 ,-15 , -150, -584};
    //int arr_size = sizeof(arr) / sizeof(arr[0]);

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));

    start = clock();
    cpt = heapSort(tab_copie, BENCHMARK_SIZE);
    end = clock();

    printf("cpt  heapSort : %d\n", cpt);
    int i;
    //for (i = 0; i < BENCHMARK_SIZE; i++)
    //    printf("%d ", tab_copie[i]);
    //printf("\n");
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("HeapSort() took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");

    // ***************************************************************************************

    printf("\nbubbleSort() starts \n");

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));
    start = clock();
    cpt = bubbleSort(tab_copie, BENCHMARK_SIZE);
    end = clock();

    printf("Compteur  bubbleSortSort : %d\n", cpt);
    //for (i = 0; i < BENCHMARK_SIZE; i++)
    //    printf("%d ", tab_copie[i]);
    //printf("\n");

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("bubbleSort() took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");

    // ***************************************************************************************

    printf("\nmergeSort() starts \n");

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));
    start = clock();
    cpt = mergeSort(tab_copie, 0, BENCHMARK_SIZE - 1);
    end = clock();

    printf("Compteur  mergeSort : %d\n", cpt);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("mergeSort()() took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");

    // ***************************************************************************************

    printf("\nquickSort() LAST starts \n");

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));
    start = clock();
    cpt = quickSort(tab_copie, 0, BENCHMARK_SIZE - 1, LAST);
    end = clock();

    printf("Compteur  quickSort : %d\n", cpt);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("quickSort() LAST took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");

    // ***************************************************************************************

    printf("\nquickSort() RANDOM starts \n");

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));
    start = clock();
    cpt = quickSort(tab_copie, 0, BENCHMARK_SIZE - 1, RANDOM);
    end = clock();

    printf("Compteur  quickSort : %d\n", cpt);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("quickSort()RANDOM took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");

    // ***************************************************************************************

    printf("\nquickSort() MEDIAN starts \n");

    memcpy(tab_copie, tab_original, BENCHMARK_SIZE * sizeof(int));
    start = clock();
    cpt = quickSort(tab_copie, 0, BENCHMARK_SIZE - 1, MEDIAN);
    end = clock();

    printf("Compteur  quickSort : %d\n", cpt);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC ;
    printf("quickSort() MEDIAN took %f seconds to execute \n", cpu_time_used);
    printf("\n************************\n");


    free(tab_original);
    free(tab_copie);

}