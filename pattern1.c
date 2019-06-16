#include <stdio.h>

main()
{
	int i, j, rows;
	
	printf("Enter the number of rows(odd only)");
	scanf("%")

	for(i=0; i<rows; i++){
		if(i<4){
			for(j=0; j<=i; j++){
				printf("%d ",(2*j+1));
			}
		}
		else{
			for(j=0;j<(7-i);j++){
				printf("%d ",(2*j+1));
			}
		}
		printf("\n");
	}
}
