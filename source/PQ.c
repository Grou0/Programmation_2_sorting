//
// Created by gma on 12-02-26.
//

#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

#define MAX 50000

struct PQ{
    int* heap;              // binary heap représenté par un tableau
    int (*f)(int, int);     // Fonction de comparaison pour définir la priorité
    int max;                // Nombre max d'éléments que l'on peut mettre dans notre heap
    int last;               // indice de la première case libre
    int cpt_operation ;
};
//typedef struct PQ* PQ_t;

void bubbleUp(PQ_t pq, int indice);
void bubbleDown(PQ_t pq, int indice);

PQ_t create(int (*leq)(int,int)) {
    PQ_t pq = malloc(sizeof(*pq));
    if (!pq) return NULL;
    pq->max = MAX ;
    pq->heap = malloc(sizeof(*(pq->heap))*(pq->max));
    pq->f = leq ;
    pq->last = 0;
    pq->cpt_operation = 0 ;
    return pq ;
}

void swapHP(int* a, int* b) {
    int tmp = *a ;
    *a = *b ;
    *b = tmp ;
}


void enqueue(PQ_t pq, int value) {
    if (pq->last >= pq->max) {
        //printf("Priority queue is full\n");
        return;
    }
    pq->heap[pq->last] = value;
    bubbleUp(pq, pq->last);
    pq->last++;
}

int serve(PQ_t pq) {  //dequeue
    if (pq->last == 0) {
        //printf("Priority queue is empty\n");
        return -1;
    }
    int value = pq->heap[0];
    pq->heap[0] = pq->heap[pq->last-1];   //on remplace le premier élément avec le dernier élément (bulle la plus à droite)
    pq->last--;
    bubbleDown(pq,0);               //On redescend depuis le 0
    return value;
}

int sizePQ(PQ_t pq){
    if (!pq) return -1;
    return pq->last;
}

//maintain heap property during insertion
//  Quand tu ajoutes un élément : tu le mets à la fin du tableau mais il n’est peut-être pas à la bonne place
//  BUT : Remonter l’élément tant qu’il a une priorité plus élevée que son parent.
//  COMMENT : On compare avec le parent. Si l’ordre n’est pas respecté → on échange.
void bubbleUp(PQ_t pq, int indice) {
    while (indice > 0) {
        int parent = (indice - 1)/2;
        int leq = pq->f(pq->heap[indice] , pq->heap[parent]);
        if (leq == 1) {
            swapHP(&(pq->heap[indice]), &(pq->heap[parent]));
            indice = parent;
            pq->cpt_operation++;
        }else{
            return;
        }
    }
}

//maintain heap property after a removal
//  Quand on retire la racine : on met le dernier élément à la racine mais il n’est probablement pas à sa place
//  BUT : Descendre l’élément tant qu’un de ses enfants a une priorité plus élevée.
//  COMMENT: On compare avec les enfants. On échange avec celui qui doit passer devant.
void bubbleDown(PQ_t pq, int indice) {

    int left  = 2*indice + 1 ;
    int right = 2*indice + 2 ;

    while (left < pq->last) { //tant qu'on a un enfant à gauche, on continue

        int best  = left;

        if (right < pq->last && ((pq->f(pq->heap[right] , pq->heap[left])) > 0 )){
            best = right;
        }

        if (pq->f(pq->heap[best] , pq->heap[indice]) > 0){
            swapHP(&(pq->heap[indice]), &(pq->heap[best]));
            indice = best;
            pq->cpt_operation++;
        }
        else {
            break;
        }

        //int left = (indice+1)*2;
        //int right = (indice+1)*2 -1;
        left  = 2 * indice + 1 ;
        right = 2 * indice + 2 ;

    }
}

int getPQcpt(PQ_t pq) {
    if (!pq) return -1;
    return pq->cpt_operation;
}

void freePQ(PQ_t pq){
    free(pq->heap);
    free(pq);
}

