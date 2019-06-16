#include <stdio.h>

main(){
	int num, i, originalnum, sumOdd=0, sumEven=0;
	
	printf("Enter any number: ");
	scanf("%d",&num);
	
	originalnum = num;
	
	int digits=0;
	
	for(i=0;num>0;i++){
		num /= 10;
		digits++;
	}
	
	for(i=1;i<=digits;i++){
		if(i%2==0){
				sumEven += originalnum%10;
				originalnum /= 10;	
		}
		else{
			sumOdd += originalnum%10;
			originalnum /= 10;
		}
	}
	
	int temp=0;
	
	if(digits%2==0){
		temp = sumEven;
		sumEven = sumOdd;
		sumOdd  = temp;
	}
	printf("Sum of even positioned digits: %d\n",sumEven);
	printf("Sum of odd  positioned digits: %d\n",sumOdd);
}
