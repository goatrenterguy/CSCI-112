//Ben Guericke
//3-4-2019
//CSCI 112
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Write function fact_calc that takes in an int n and reutrns a string
char* fact_calc(int n, char* out){
	int total = n;
	char buffer[30];
	//Convert int to string
	sprintf(buffer,"%d",n);
	//Add Varous elements to the string
	strcat(out, "* ");
	strcat(out, buffer);
	strcat(out, "! = ");
	//iterate through the factorial
	do{
		sprintf(buffer,"%d",n);
		total *= n - 1;
		n--;
		strcat(out, buffer);
		strcat(out," X ");
	}while(n>1);
	strcat(out, "1 = ");
       	sprintf(buffer,"%d",total);
	strcat(out, buffer);	
	strcat(out, " *");
	return out;
}
//Method to print the lines of stars
void printStars(int n, char* out){
	int i = 0;
	char* stars = (char*)malloc(sizeof(char) * 80);
	while(out[i] != '\0'){
		strcat(stars,"*");
		i++;
	}
	//iterate through the length of out and astrcats a * each time
	printf("%s\n",stars);
}
//Write main
	int main(void){
	int n;
	while (n != -1){
		char* out = (char*)malloc(sizeof(char) * 80);
		printf("Enter an integer between 0 and 9 or -1 to quit: \n");
		scanf("%d",&n);
		if (n != -1) {
		out = fact_calc(n,out);
		printStars(n,out);
		printf("%s\n",out);
		printStars(n,out);
		}
	}
}
