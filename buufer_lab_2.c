// Program to find the sum of each row and each column of a matrix 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

main()
{
	char flag, *pos;
	int i, j, a[10][10], r, c;
	double rsum[10], csum[10];
	
	printf("----------------------------------------------------------------- \n");
	printf(" Program to find the sum of each row and each column of a matrix \n");
	printf("----------------------------------------------------------------- \n\n");	
	printf("------------------------\n");
	printf(" Enter the no. of rows: ");
	scanf("%d", &r);
	printf("------------------------\n");
	printf("---------------------------\n");
	printf(" Enter the no. of columns: ");
	scanf("%d", &c);
	printf("---------------------------\n");
	
	printf("-----------------------------------\n");
	printf(" Enter the elements of matrix \n");
	printf("-----------------------------------\n");
	
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("-----------------------------------------------\n");
			printf(" Enter the value of element a[%d][%d] of matrix: ", i + 1, j + 1);
			scanf("%d", & a[i][j]);
			printf("-----------------------------------------------\n");
			
			csum[j] += a[i][j]; 
			rsum[i] += a[i][j];
		}
	}
	
	printf("---------------------------------- \n");
	for(i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
			
			if(j == c - 1)
				printf("\n");
		}
	}
	printf("---------------------------------- \n");
	
	printf("\n");
	printf("---------------------------------------------- \n");
	for(i = 0; i < r; i++)
		printf("The sum of no. %d row elements is: %.2lf\n", i + 1, rsum[i]);
	printf("---------------------------------------------- \n");
	
	printf("\n");
	printf("---------------------------------------------- \n");
	for(j = 0; j < c; j++)
		printf("The sum of no. %d column elements is: %.2lf\n", j + 1, csum[j]);
	printf("---------------------------------------------- \n");	
}
