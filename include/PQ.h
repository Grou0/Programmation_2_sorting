/*

Auteur: Cédric Libert
Description: file d'entiers. On peut y ajouter des éléments et récupérer à chaque fois l'élément qui est dans la
file depuis le plus longtemps.

*/
#ifndef PQ_H
#define PQ_H

#include <stdlib.h>
#include <stdio.h>


struct PQ; //déclaration du nom de ma structure
typedef struct PQ* PQ_t; //déclaration d'un alias qui désigne le type "pointeur vers struct Queue"

//PRE: /
//POST: initialise une PQ vide avec une relation d'ordre
//leq est un pointeur vers une fonction qui prend deux int et retourne un int.
//  qui permettra de définir une relation d’ordre dans notre file de priorité, en
//  disant, pour deux éléments donnés, si le premier est plus petit que le deuxième. Ça permet de définir un ordre.
PQ_t create(int (*leq)(int,int));

int empty(PQ_t);

int full(PQ_t);

//On en retire un
void enqueue(PQ_t pq, int value);

int serve(PQ_t pq);

//leq => less or equal
int leq(int value1, int value2);

void test(PQ_t pq, int (*leq)(int,int));

int sizePQ(PQ_t q);

int getPQcpt(PQ_t pq);

void freePQ(PQ_t pq);



#endif
