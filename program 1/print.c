#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

//Method to print everything and write to output file
void printClasses(FILE *f_out,class_t classes[], int count) {
    printf("--------------------\n");
    for (int i = 0; i < count; i++) {
        //Prints to screen
        printf("%-46s%s ", classes[i].name, classes[i].num);
        fprintf(f_out, "%-46s%s ", classes[i].name, classes[i].num);
        switch (classes[i].year) {
            case 1:
                printf("freshman");
                fprintf(f_out, "freshman");
                break;
            case 2:
                printf("sophomore");
                fprintf(f_out, "sophomore");
                break;
            case 3:
                printf("junior");
                fprintf(f_out, "junior");
                break;
            case 4:
                printf("senior");
                fprintf(f_out, "senior");
                break;
        }
        printf(" %s %s\n", classes[i].daysOffered, classes[i].time);
        fprintf(f_out, " %s %s\n", classes[i].daysOffered, classes[i].time);
    }
    printf("--------------------\n");
    fprintf(f_out, "--------------------\n");
}
