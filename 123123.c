#include <stdio.h>

typedef struct{
	int day, month, year;
}Date;

typedef struct{
	int consumerNumber, units;
	Date presentDate;	
	char consumerName[50];
	double amount;
}Consumer;

void inputConsumer(Consumer *c);
void printConsumer(Consumer c);
double getBill(Consumer c);

main(){
	Consumer c[10];
	int n;
	
	printf("Enter the number of consumers: ");
	scanf("%d",&n);
	
	int i;
	for(i=0;i<n;i++){
		inputConsumer(&c[i]);
	}
	for(i=0;i<n;i++){
		printConsumer(c[i]);
	}
}

void inputConsumer(Consumer *c){
	printf("\n-------------Consumer Details-------------------------\n");
	printf("------------------------------------------------------\n");
	printf("Enter the Consumer number: ");
	scanf("%d",&c->consumerNumber);
	printf("Enter the Consumer name: ");
	scanf(" %[^\n]",&c->consumerName);
	printf("Enter the number of units consumed: ");
	scanf(" %d",&c->units);
	printf("Enter the date(DD-MM-YY): ");
	scanf("%d %d %d",&c->presentDate.day,&c->presentDate.month,&c->presentDate.year);
	printf("------------------------------------------------------\n");
}

double getBill(Consumer c){
	if(c.units<=100)
		return 6.2*c.units;
	else if(c.units<=200)
		return 6.2*100 + 7.4*(c.units-100);
	else if(c.units<=300)
		return 6.2*100 + 7.4*100 + 8.5*(c.units-200);
	else
		return 6.2*100 + 7.4*100 + 8.5*100 + 9.3*(c.units-300);
}

void printConsumer(Consumer c){
	printf("\n-------------Consumer Details-------------------------\n");
	printf("------------------------------------------------------\n");
	printf("Consumer number: 	%-8d\n",c.consumerNumber);
	printf("Consumer name: 		%-10s\n",c.consumerName);
	printf("Amount to be paid:  %.2lf\n",getBill(c));
	printf("Date: 				%d-%d-%d\n",c.presentDate.day,c.presentDate.month,c.presentDate.year);
	printf("------------------------------------------------------\n");
}
