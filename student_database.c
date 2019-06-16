#include <stdio.h>
#include <windows.h>
#include <string.h>

struct student
{
	int s_roll_no, s_marks[3];
	char s_name[50], s_class[50];
}number[50];

int main()
{
	int n=0,i,j;
	char flag[50], *pos;
	
	do
	{
		system("cls");
		n=0;
		
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf(" Program to create a database of n students storing their roll number, name, class and marks in three subjects \n");
		printf("--------------------------------------------------------------------------------------------------------------\n\n\n");
			
		printf("---------------------------------------------------\n");
		printf("How many students are there? ");
		scanf("%d", &n);
		printf("---------------------------------------------------");
		
		if(n<1)
		{
			printf("---------------------------------------------------\n");
			printf("Number of students could not be less than 1\n");
			printf("---------------------------------------------------\n");
		}
		
		for(i=0;i<n && !(n<1);i++)
		{
			system("cls");
			printf("---------------------------\n");
			printf(" Enter the Student details\n");
			printf("---------------------------\n\n");
			printf("----------------------- Student %d ----------------------------------------------------\n",i+1);
			printf("Roll no.: ");
			scanf("%d", &number[i].s_roll_no);
			
			fflush(stdin);
			printf("Name: ");
			gets(number[i].s_name);
			
			fflush(stdin);
			printf("Class: ");
			gets(number[i].s_class);
			
			for(j=0;j<3;j++)
			{
				printf("Marks in the subject %d: ",j+1);
				scanf(" %d", &number[i].s_marks[j]);
				
				if((number[i].s_marks[j] < 0) || (number[i].s_marks[j] > 100))
				{
					printf("Marks in the subject %d could not be less than 0 or greater than 100\n",j+1);
					j--;	
				}
			}
			printf("---------------------------------------------------------------------------------------\n");
		}
		
		if(!(n<1))
		{
			system("cls");
			printf("---------------------------\n");
			printf(" Student details\n");
			printf("---------------------------\n\n");
		}
		
		for(i=0;i<n && !(n<1);i++)
		{
			printf("----------------------- Student %d ----------------------------------------------------\n",i+1);
			printf("Roll no.: %d",number[i].s_roll_no);
			
			if(!(strlen(number[i].s_name)))
				printf("\nName field has not been filled.\n");
			else
			{
				printf("\nName: ");
				puts(number[i].s_name);
			}
			
			if(!(strlen(number[i].s_class)))
				printf("Class field has not been filled.\n");
			else
			{
				printf("Class: ");
				puts(number[i].s_class);
			}
			
			for(j=0;j<3;j++)
			{
				printf("Marks in the subject %d is: %d\n",j+1, number[i].s_marks[j]);
			}
			printf("---------------------------------------------------------------------------------------\n\n");
		}	
		getch();
		
		system("cls");
		fflush(stdin);
		printf("---------------------------------------------------\n");
		printf("Do you want to continue? ");
		gets(flag);
		printf("---------------------------------------------------");
		
		pos = strchr(strupr(flag), 'Y');	
	} 
	while(pos);
}
