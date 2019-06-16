// Program to demonstrate the concept of matrix multiplication and also check whether the given matrix is an identity matrix or not
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
// main function starts 
int main()
{
  	int r1, c1, r2, c2, i, j, k, sum = 0, identity = 1;
  	int first[10][10], second[10][10], multiply[10][10];
  	char flag[20], *pos;
  	do
	{
	  system("cls");
	  r1 = c1 = r2 = c2 = i = j = k = sum = 0;
	  identity = 1;
	  printf("Enter the number of rows and columns of first matrix \n");
	  scanf("%d%d", &r1, &c1);
	  printf("Enter the elements of first matrix \n");
	 
	  for (  i = 0 ; i < r1 ; i++ )
	     forj = 0 ; j < c1 ; j++ )
	      {scanf("%d", &first[i][j]);
	 
	  printf("Enter the number of rows and columns of second matrix \n");
	  scanf("%d%d", &r2, &c2);
	 
	  if ( c1 != r2 )
	    printf("Matrices with entered orders can't be multiplied with each other.\n");
	  else
	  {
	    printf("Enter the elements of second matrix \n");
	 
	    for ( i = 0 ; i < r2 ; i++ )
	      for ( j = 0 ; j < c2 ; j++ )
	        scanf("%d", &second[i][j]);
	 
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
	 
	    printf("Product of entered matrices:-\n");
	 
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
 	 	if (identity == 1 )
            printf("First matrix is identity matrix \n");
        else
            printf("First matrix is not a identity matrix \n");
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
 	 	if (identity == 1 )
            printf("Second matrix is identity matrix \n");
        else
            printf("Second matrix is not a identity matrix \n");
        getch();
	  
	  system("cls");
	  printf("Do you want to continue? ");
	  fflush(stdin);
	  gets(flag);
	  pos = strchr(strupr(flag), 'Y');
	}
	while(pos);
}
