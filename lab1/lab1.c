#include <stdio.h>

int main(void){
	double initial,final,dis,cost;
	//Prompt user
	printf("Enter beginning odometer reading=> ");
	scanf("%lf",&initial);
	printf("Enter ending odometer reading=> ");
	scanf("%lf",&final);
	//Calculate distnace traveled and cost
	dis = final-initial;
	cost = dis * 0.35;
	printf("You traveled %.1f miles. At $0.35 per mile, \nyour reimbursment is $%.2lf\n", dis, cost);
}
