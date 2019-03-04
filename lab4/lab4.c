//Ben Guericke
//2-1-2019
//CSCI 112

#include <stdio.h>

//Takes in an input file, two arrays, and the arrays max size fills array with with info from input file and returns the number of (x,y) cordinants
int get_corners(double x[], double y[]){
	int i=0,num_items;
	do {
		num_items = scanf("%le %le",&x[i],&y[i]);
		i++;	
	} while (num_items > 0);
	i--;
	return(i);
}
//Takes in two type double arrays and outputs the contents in two columns
void output_corners(double x[], double y[], int max){
	int i;
	printf("x	y\n");
	printf("--------------\n");
	for (i = 0; i < max; i++){
		printf("%.2lf	%.2lf\n", x[i],y[i]);
	}

}
//polygon_area takes in two double arrays x and y and size, returns the area of the polygon
double polygon_area(double x[], double y[], int max){
	double area;
	int i;
	//For loop iterates through all the variables adding them up 
	for (i = 0; i < max - 1; ++i){
		area += (x[i] + x[i+1]) * (y[i] - y[i+1]);
	}
	return area/2.0;
}
//main tests the program and calls the functions
int main(void){
	double x[20],y[20];
	int corners;
	double area;
	//Gets the number of conrenrs and reads in file
	corners = get_corners(x,y);
	//Prints the x and y cordinants in 2 columns
	output_corners(x,y,corners);
	//Gets the area of the the polygon
	area = polygon_area(x,y,corners);
	//Prints the area
	printf("Area is: %.2lf\n",area);
}

