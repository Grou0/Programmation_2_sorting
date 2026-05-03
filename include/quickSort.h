//
// Created by gma on 28-03-26.
//

#ifndef S7_SORT_REPO_QUICKSORT_H
#define S7_SORT_REPO_QUICKSORT_H

// Choix du pivot
// mode 1 : LAST   = dernier élément (comportement actuel)
// mode 2 : RANDOM = pivot aléatoire
// mode 3 : MEDIAN = médiane de trois

enum mode { LAST, RANDOM, MEDIAN };

int quickSort(int arr[], int low, int high, int mode);

#endif //S7_SORT_REPO_QUICKSORT_H