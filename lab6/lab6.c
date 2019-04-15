//Ben Guericke
//3-4-2019
//CSCI 112

#include <stdio.h>
//Function that lists all of the one element
void one_ele_subs(char* input, int length){
	if(length != 0){
		printf("{%c}\n",input[4-length]);
		one_ele_subs(input,length-1);
	}	       
}
//Function taht list all of the two elements
void two_ele_subs(char* input, int length){
	int i;
	for (i = 4 - length; i < 3; i++){
		printf("{%c, %c}\n",input[4-length], input[i+1]);
	}
	if (length > 0){		
		two_ele_subs(input, length-1);
	}
}


void three_ele_subs(char* input, int length){
	int i;
	int n;
        for (i = 4 - length; i < 3; i++){
		for (n = i; n < 2; n++){
                printf("{%c, %c, %c}\n",input[4-length], input[i+1], input[n+2]);
		}	
	}
        if (length > 0){
                three_ele_subs(input, length-1);
        }
}
//Main method takes in 4 character string from command line
int main(int argc, char *argv[]){
	if(argc == 2) {
	int length = 0;
	char* input = argv[1];
	while (input[length] != '\0') {
    		length++;
	}
	if (length != 4) {
        	printf("ERROR: Please enter a string of length 4\n");
    	}else{
    	printf("one_ele_subs\n");
    	printf("%s\n",input);
    	one_ele_subs(input,length);
	printf("two_ele_subs\n");
	printf("%s\n", input);
	two_ele_subs(input,length);
	printf("three_ele_subs\n");
        printf("%s\n", input);
        three_ele_subs(input,length);
	}
	} else {
	printf("People enter a four letter word\n");
	}
}
