//Ben Guericke
//2-1-2019
//CSCI 112
#include <stdio.h>
#include <math.h>
double calcPayment(double p, double i, double n){
	return ((i*p)/(1-(pow((1+(i)),-n))));
}

int main(int argc, char** argv){
	//Inizlaize principal, anual intrest rate, number of payments, and payment
	double principal, intrestRate, numPayments, payment, final, intrest, balance;
	char temp[3];
	//Take the argv and assign the variables and remove commas from the doubles
	if (argc != 11) {
		printf("ERROR: wrong number of parameter\n");
	}  
	sscanf(argv[2],"%lf%s", &principal, temp);
	sscanf(argv[6],"%lf%s", &intrestRate, temp);
	sscanf(argv[10],"%lf", &numPayments);
	intrestRate = intrestRate/1200;
	balance = principal;
	//Calculate the montly payment
	payment = calcPayment(principal,intrestRate,numPayments);
	final = numPayments * payment;
	//Print the monthly rate
	printf("With a principal of %.2lf, a intrest rate of %.2lf, and %.2lf monthly payments,\nyour monthly payment should be %.2lf, your total payment amounts to: $%.2lf\n", principal, intrestRate, numPayments, payment, final);
	//Print labels for table
	printf("\nPayment	Intrest  Principal  Balance\n");
	int i;
	//Iterates through and prints the payment number interest principal and the balance
	for (i = 0; i < numPayments; ++i) {
		intrest = balance*intrestRate;
		balance = balance+intrest-payment;
		printf("%d	%.2lf    %.2lf	   %.2lf\n",i+1, intrest, (payment - intrest), balance);
	}
	printf("Final payment	$%.2lf\n",payment);
}
