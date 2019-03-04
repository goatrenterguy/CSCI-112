//Ben Guericke 2-1-2019
#include <stdio.h>
#include <math.h>
//Get the status based on BMI
void computeStatus(double BMI){
	if (BMI < 18.5) {
		printf("This means you are underweight\n");
	} else if (BMI >= 18.5 && BMI < 25) {
		printf("This means you are normal\n");
	} else if (BMI >= 25 && BMI < 30) {
		printf("This means you are overweight\n");
	} else {
		printf("This means you are obese\n");
	}
}

int main(void){
	//Initialize height weight status and bmi
	double height, weight, BMI;
	//Prompt user for height and weight
	do {
		height = -1;
		printf("Enter height (in inches): ");
		scanf("%lf", &height);
	} while(height < 0);
	do {
		weight = -1;
		printf("Enter weight (in pounds): ");
		scanf("%lf", &weight);
	} while (weight < 0);
	//Compute BMI
	BMI = ((703 * weight)/(pow(height,2)));
	//Print Height Weight BMI and weight status
	printf("Your height is %.0lf, and your weight is %.1lf, which gives you a BMI of %.lf\n", height, weight, BMI);
	computeStatus(BMI);
}	
