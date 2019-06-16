// Program to demonstrate the concept of matrix multiplication and also check whether the given matrix is an identity matrix or not
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
// main function starts 
int main()
{
  	int r1, c1, r2, c2, i, j, k, sum = 0, identity = 1, opt;
  	int first[10][10], second[10][10], multiply[10][10];
  	char flag[20], *pos;
  	do
	{
	  system("cls");
	  r1 = c1 = r2 = c2 = i = j = k = sum = 0;
	  identity = 1;
	  printf(" Program for matrix multiplication and to check whether the given matrix is an identity matrix or not \n");
	  printf("------------------------------------------------------------------------------------------------------ \n");
	  printf("------------------------------------------------------------------------------------------------------ \n\n");
	  printf("---------------------------- \n");
	  printf("1. Matrix multiplicatin \n");
	  printf("2. Identity matrix or not \n");
	  printf("---------------------------- \n");
	  printf("Selected option: ");
	  scanf("%d", &opt);
	  printf("---------------------------- \n");
	  printf("\n");
	  switch(opt)
	  {
		case 1:	  
			  system("cls");
			  printf("---------------------------- \n");
			  printf("1. Matrix multiplicatin \n");
			  printf("---------------------------- \n\n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of rows of first matrix: ");
			  scanf("%d", &r1);
			  printf("--------------------------------------------------------------- \n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of columns of first matrix: ");
			  scanf("%d", &c1);
			  printf("--------------------------------------------------------------- \n");
			  printf("------------------------------------ \n");  
			  printf(" Enter the elements of first matrix  \n");
			  printf("------------------------------------ \n");
			  for (  i = 0 ; i < r1 && r1 > 0 && c1 > 0; i++ ) // to iterate the rows
			  {
			  	 for(j = 0 ; j < c1 ; j++ ) // to iterate the columns
			    {
				   	printf("Enter the element a%d%d of first matrix: ", i+1, j+1);
					scanf("%d", &first[i][j]);
				}
			  }
			  printf("\n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of rows of second matrix: ");
			  scanf("%d", &r2);
			  printf("--------------------------------------------------------------- \n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of columns of second matrix: ");
			  scanf("%d", &c2);
			  printf("--------------------------------------------------------------- \n");
			  if(!(r1 > 0) || !(c1 > 0) || !(r2 > 0) || !(c2 > 0))
			  	break;
			  if ( c1 != r2 )
			  {
			  	system("cls");
			  	printf("For multiplication of two matrices: No. of columns of first matrix should be equal to the number of rows of second matrix\n");
			  	getch();
			  }
			  else
			  {
			    printf("------------------------------------- \n");
				printf(" Enter the elements of second matrix \n");
			    printf("------------------------------------- \n");
			 
			    for ( i = 0 ; i < r2 && r2 > 0 && c2 > 0; i++ ) // to iterate the rows
			    {
					for ( j = 0 ; j < c2 ; j++ ) // to iterate the rows
			        {
						printf("Enter the element b%d%d of second matrix: ", i+1, j+1);
						scanf("%d", &second[i][j]);
					}
				}
			 
			    for ( i = 0 ; i < r1 ; i++ )
			    {
			      for ( j = 0 ; j < c2 ; j++ )
			      {
			        for ( k = 0 ; k < r2 ; k++ )
			        {
			          sum = sum + first[i][k]*second[k][j];
			        }
			 
			        multiply[i][j] = sum;
			        sum = 0;
			      }
			    }
			    
			    printf("\n");
			    printf("--------------\n");
				printf(" First Matrix \n");
				printf("--------------\n");
				for (  i = 0 ; i < r1 ; i++ ) // to iterate the rows
			  	{
				  	for(j = 0 ; j < c1 ; j++ ) // to iterate the columns
			   		{
						printf("%d ", first[i][j]);
						if( j == c1 - 1)
						{
							printf("\n");
						}
					}
				}
				printf("--------------\n");
				printf("\n");
				printf("---------------\n");
				printf(" Second matrix \n");
				printf("---------------\n");
				for ( i = 0 ; i < r2 ; i++ ) // to iterate the rows
			    {
					for ( j = 0 ; j < c2 ; j++ ) // to iterate the rows
			        {
						printf("%d ", second[i][j]);
						if( j == c2 - 1)
						{
							printf("\n");
						}
					}
				}
			 	printf("---------------\n");
				printf("\n");
			    printf("-------------------------------\n");
				printf(" Product of entered matrices:- \n");
			 	printf("-------------------------------\n");
			    for ( i = 0 ; i < r1 ; i++ )
			    {
			      for ( j = 0 ; j < c2 ; j++ )
			        printf("%d\t", multiply[i][j]);
			 
			      printf("\n");
			    }
			    getch();
			  }
			  	/*  Check for unit (or identity) matrix */
				for (i = 0; i < r1; i++) 
		        {
		            for (j = 0; j < c1; j++)
		            {
		                if (first[i][j] != 1 && first[j][i] != 0)
		                {
		                    identity = 0;
		                    break;
		                }
		            }
		        }
		 	 	printf("\n");
		 	 	printf("----------------------------------------------- \n");
			  	if(c1 == r2)
			  	{
					if (identity == 1 && first[0][0] == 1)
			            printf("First matrix is an identity matrix \n");
			        else
			            printf("First matrix is not an identity matrix \n");
				  	identity = 1;
					/*  Check for unit (or identity) matrix */
					for (i = 0; i < r2; i++) 
			        {
			            for (j = 0; j < c2; j++)
			            {
			                if (second[i][j] != 1 && second[j][i] != 0)
			                {
			                    identity = 0;
			                    break;
			                }
			            }
			        }
			 	 	if (identity == 1 && first[0][0] == 1)
			            printf("Second matrix is an identity matrix \n");
			        else
			            printf("Second matrix is not an identity matrix \n");
			        printf("----------------------------------------------- \n");
					getch();
			  	}
		break;
		
		case 2:
			  system("cls");
			  printf("---------------------------- \n");
			  printf("2. Identity matrix or not \n");
			  printf("---------------------------- \n\n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of rows of matrix: ");
			  scanf("%d", &r1);
			  printf("--------------------------------------------------------------- \n");
			  printf("--------------------------------------------------------------- \n");
			  printf(" Enter the number of columns of matrix: ");
			  scanf("%d", &c1);
			  printf("--------------------------------------------------------------- \n");
			  if(!(r1 > 0) || !(c1 > 0))
			  	break;
			  printf("------------------------------------ \n");  
			  printf(" Enter the elements of matrix  \n");
			  printf("------------------------------------ \n");
			  for (  i = 0 ; i < r1 && r1 > 0 && c1 > 0; i++ ) // to iterate the rows
			  {
			  	 for(j = 0 ; j < c1 ; j++ ) // to iterate the columns
			    {
				   	printf("Enter the element a%d%d of matrix: ", i+1, j+1);
					scanf("%d", &first[i][j]);
				}
			  }
			  	printf("\n");
		 	 	printf("----------------------------------------------- \n");
			  	/*  Check for unit (or identity) matrix */
					for (i = 0; i < r2; i++) 
			        {
			            for (j = 0; j < c2; j++)
			            {
			                if (first[i][j] != 1 && first[j][i] != 0)
			                {
			                    identity = 0;
			                    break;
			                }
			            }
			        }
			 	 	if (identity == 1 && first[0][0] == 1)
			            printf("This matrix is an identity matrix \n");
			        else
			            printf("This matrix is not an identity matrix \n");
			    printf("----------------------------------------------- \n");
				getch();
			  	
		break;
		
		default: printf("Wrong input");
		break;
	   }
	    if(!(r1 > 0) || !(c1 > 0))
			  	break;
		system("cls");
		printf("Do you want to continue? ");
		fflush(stdin);
		gets(flag);
		pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
	if(!(r1 > 0) || !(c1 > 0) || !(r2 > 0) || !(c2 > 0))
	{
		printf("\nThe number of rows or columns could not be 0 or negative \n");
		getch();
	}
	printf("you quit the program");
	getch();
}
