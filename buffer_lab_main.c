// Program to copy the elements of one array into another
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

main()
{
	char first[50], second[50], flag[50], *pos;
	int i, j, opt;
	int a[10][10], r, c;
	double rsum[10], csum[10];
	
	do
	{
		system("cls");
		printf("-------------------------------------------------------------------------------------------------------- \n");
		printf(" Program to copy the elements of one array into another and to find he  sum of each row and each coulmn \n");
		printf("-------------------------------------------------------------------------------------------------------- \n\n");	
		printf("---------------------\n");
		printf(" 1. Copy \n");
		printf(" 2. Sum \n");
		printf("---------------------\n");
		printf(" Selected option is: ");
		scanf("%d", &opt);
		printf("---------------------\n");
		
		switch(opt)
		{
			case 1:
					system("cls");
					fflush(stdin);
					printf("-------------------------------------------------------- \n");
					printf(" Program to copy the elements of one array into another \n");
					printf("-------------------------------------------------------- \n\n");	
					printf("------------------------------------------------------------------------------------------ \n");
					printf(" Enter the elements of first array: ");
					gets(first);
					printf("------------------------------------------------------------------------------------------ \n");
					
					if(first[0] == '\0')
					break;
					for(i = 0; i == 0 || !(first[i  - 1] == '\0'); i++)
						second[i] = first[i];
					
					printf("------------------------------------------------------------------------------------------ \n");
					printf(" The copied string is: %s \n", second);
					printf("------------------------------------------------------------------------------------------ \n");
			break;
			
			case 2:
					system("cls");
					fflush(stdin);
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
			break;
			
			default:
					system("cls"); 
					printf("Wrong input");		
		}
		getch();
		system("cls");
		fflush(stdin);
		if(first[0] == '\0')
		{
			printf("--------------\n");
			printf(" Empty string\n");
			printf("--------------\n");
		}
		printf("--------------------------\n");
		printf(" Do you want to continue: ");
		gets(flag);
		printf("--------------------------\n");
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	
	system("cls");
	fflush(stdin);
	printf("----------------------\n");
	printf(" You quit the program \n");
	printf("----------------------\n");
	getch();
}
