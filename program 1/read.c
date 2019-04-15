#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

//Read in all classes
int readClasses(class_t classes[]){
    FILE *f_in = fopen("/public/csci112sp19/pgm1/classes.txt", "r");
    //Checks if file exists
    if (f_in == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char buff[80];
    int count = 0;
    char *result;
    //Goes through the file line by line
    while (fgets(buff, 80, f_in) != NULL){
        result = strtok(buff, " ");
        strcpy(classes[count].num, result);
        result = strtok(NULL, "$");
        strcpy(classes[count].name, result);
        result = strtok(NULL, " ");
        strcpy(classes[count].daysOffered, result);
        result = strtok(NULL, " ");
        strcpy(classes[count].time, result);
        result = strtok(NULL, " ");
        sscanf(result, "%d", &classes[count].year);
        ++count;
    }
    fclose(f_in);
    return count;
}


