//
// Created by gma on 15-04-26.
//

#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "heapSort.h"

int leq(int a, int b);

int heapSort(int tab[], int taille) {
    if (taille <= 0) return -1;

    PQ_t pq = create(leq) ;

    for (int i = 0; i < taille ; i++) {
        enqueue(pq, tab[i]);
    }

    for (int i = 0; i < taille ; i++) {
        tab[i] = serve(pq);
    }

    int cpt = getPQcpt(pq);

    free(pq);

    return cpt;
}




int leq(int a, int b) { //Permettra de faire un tri en ordre croissant pour avoir un min-heap
    if (a < b ) return 1;
    else return 0;
}