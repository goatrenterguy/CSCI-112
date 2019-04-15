#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"
//Method that prompts the user and computes logic for prompts
void prompt(class_t classes[]) {
    int count, input;

    count = readClasses(classes);
    while (input != -1) {
        printf("Enter:\n--------------------\n1 to print classes by CSCI number\n2 to print classes on MWF and TR\n3 to print classes at specific time\n4 to  Print classes available to freshman, sophomore, junior or senior\n-1 to quit\n--------------------\n");
        int i, j = 0, blah;
        char days[80], times[80], year;
        scanf("%d", &input);
        class_t tmpClasses[15];

        if (input != -1) {
            switch (input) {
                case 1: //Sort by CSCI number
                    sortCSCI(classes, count);
                    printClasses(f_out, classes, count);
                    break;
                case 2: //Print classes on MWF and TR
                    printf("Enter days of week: (MWF or TR)\n");
                    scanf("%s", days);
                    //Iterates through array of classes
                    for (i = 0; i < count; ++i) {
                        //checks if class_t in classes is on selected day and copies to tmpClasses
                        if (strcmp(classes[i].daysOffered, days) == 0) {
                            strcpy(tmpClasses[j].num, classes[i].num);
                            strcpy(tmpClasses[j].name, classes[i].name);
                            strcpy(tmpClasses[j].daysOffered, classes[i].daysOffered);
                            strcpy(tmpClasses[j].time, classes[i].time);
                            blah = classes[i].year;
                            tmpClasses[j].year = blah;
                            j++;
                        }
                    }
                    sortCSCI(tmpClasses, j);
                    printClasses(f_out, tmpClasses, j);
                    break;
                case 3:
                    printf("Enter days of week and start time to search for Example: TR 1200-1250\n");
                    scanf("%s%s", days, times);
                    int found = 0;
                    //Iterates through array of classes
                    for (i = 0; i < count; ++i) {
                        //Finds class that matches if it doesnt prints error
                        if ((strcmp(classes[i].daysOffered, days) == 0) && (strcmp(classes[i].time, times) == 0)) {
                            strcpy(tmpClasses[j].num, classes[i].num);
                            strcpy(tmpClasses[j].name, classes[i].name);
                            strcpy(tmpClasses[j].daysOffered, classes[i].daysOffered);
                            strcpy(tmpClasses[j].time, classes[i].time);
                            blah = classes[i].year;
                            tmpClasses[j].year = blah;
                            j++;
                            found = 1;
                        }

                    }
                    if (found != 1) {
                        printf("ERROR: Class not found\n");
                    } else {
                        printClasses(f_out, tmpClasses, j);
                    }
                    break;
                case 4: //Print by year
                    printf("Enter first letter of year: (senior is 'r')\n");
                    scanf("%s", &year);
                    int numYear = 0;
                    switch (year) {
                        case 'f':
                            numYear = 1;
                            break;
                        case 's':
                            numYear = 2;
                            break;
                        case 'j':
                            numYear = 3;
                            break;
                        case 'r':
                            numYear = 4;
                            break;
                        default:
                            printf("Error: Year not found");
                    }
                    if (numYear != 0) {
                        //Iterates through array of classes
                        for (i = 0; i < count; ++i) {
                            //Searches for classes offered in year that user inputs
                            if (classes[i].year == numYear) {
                                strcpy(tmpClasses[j].num, classes[i].num);
                                strcpy(tmpClasses[j].name, classes[i].name);
                                strcpy(tmpClasses[j].daysOffered, classes[i].daysOffered);
                                strcpy(tmpClasses[j].time, classes[i].time);
                                blah = classes[i].year;
                                tmpClasses[j].year = blah;
                                j++;
                            }
                        }
                    }
                    sortCSCI(tmpClasses, j);
                    printClasses(f_out, tmpClasses, j);
                    break;
                default:
                    printf("ERROR");
            }
        }
    }

}


