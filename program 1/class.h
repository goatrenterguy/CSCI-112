//Defines the structure of class_t
typedef struct{
    char num[50], name[50], daysOffered[50], time[50];
    int year;
} class_t;

//Defines methods so that they can be used between classes
int readClasses(class_t classes[]);
void sortCSCI(class_t classes[], int n);
void printClasses(FILE *f_out,class_t classes[], int count);
void prompt(class_t classes[]);
