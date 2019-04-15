#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"
void swap(class_t*, class_t*);

//Function to sort by CSCI number
void sortCSCI(class_t classes[], int n) {
    int i,j;
    for (i = 0; i < n; ++i){
        for (j=i; j < n; ++j) {
            if (strcmp(classes[i].num, classes[j].num) > 0) {
                swap(&classes[i], &classes[j]);
            }

        }
    }
}
//Swaps the position of two class_t in an array of class_t
void swap(class_t *a, class_t *b){
    class_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

