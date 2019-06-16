//Program to sort an array using pointers
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int *a,n,i,j,temp;
	char flag[100], *pos;
	do
	{
		system("cls");
		// print a message
	    printf("-----------------------------------------\n");
		printf(" Program to sort an array using pointers \n");
		printf("-----------------------------------------\n\n\n");
		
		printf("------------------------\n");
		printf(" Enter size of array: ");
		scanf("%d",&n);
		printf("------------------------\n");
		a=calloc(sizeof(int),n);
		
		if(n<1)
		{
			printf("---------------------------------------------------\n");
			printf("Number of elements could not be less than 0\n");
			printf("---------------------------------------------------\n");
		}
		
		if(!(n<1))
		{
			system("cls");
			printf("------------------------\n");
			printf(" Enter %d Elements \n",n);
			printf("------------------------\n");
		}
		
		for(i=0;i<n && !(n<1);i++)
		{
			printf("\n------------------------\n");
			printf(" Enter element no.%d: ",i+1);
			scanf("%d",a+i);
			printf("------------------------\n\n");
		}
		
		if(!(n<1))
		{
			system("cls");
			printf("--------------------------------------\n");
			printf(" Before sorting it in ascending order:\n");	
		}
		
		for(i=0;i<n && !(n<1);i++)
		{
			if((i+1)%5 == 1)
				printf(" ");
			
			printf("%d\t",*(a+i));
			
			if((i+1)%5 == 0)
				printf("\n");
		}
		if(!(n<1))
		{
			printf("\n--------------------------------------\n");	
		}
		getch();
	
		for(i=0;i<n-1 && !(n<1);i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(*(a+j)>*(a+j+1))
				{
					temp=*(a+j);
					*(a+j)=*(a+j+1);
					*(a+j+1)=temp;
				}
			}
		}
		
		if(!(n<1))
		{
			system("cls");
			printf("--------------------------------------\n");
			printf(" After sorting it in ascending order:\n");	
		}
		
		for(i=0;i<n && !(n<1);i++)
		{
			if((i+1)%5 == 1)
				printf(" ");
			
			printf("%d\t",*(a+i));
			
			if((i+1)%5 == 0)
				printf("\n");
		}
		if(!(n<1))
		{
			printf("\n--------------------------------------\n");	
		}
		getch();
		
		system("cls");
		printf("\n--------------------------------------\n");
		printf(" Do you want to continue? ");
		scanf(" %s", &flag);
		printf("\n--------------------------------------\n");
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	return 0;
				
}
