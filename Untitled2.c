// program to implement the usage of while loop to find the factorial of a given number
// Coded by Jaspreet Singh
// for standard input and output
#include <stdio.h> 
// for console input and output
#include <conio.h>
#include <windows.h>
// Maximum number of digits in output
#define MAX 510999
 
// main function starts
main()
{
	// declare variables to store the number whose factorial is to be find, factorial, counter and flag
	int res[MAX], res_size = 1, prod, i, n, x; 
	int carry = 0;  // Initialize carry
    // Initialize result
    res[0] = 1;
    // print a message
    printf("Enter the number whose factorial is to be find");
    // store the number in a variable
	scanf("%d",&n);
 	// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
   	for (x=2; x<= n; x++)
	{
		// multiply x with the number 
		// represented by res[]
		// res_size is size of res[] or number of digits in the number represented by res[] 
		// uses simple school mathematics for multiplication
		// One by one multiply n with individual digits of res[]
	    for (i=0; i<res_size; i++)
	    {
	        prod = res[i] * x + carry;
	 
	        // Store last digit of 'prod' in res[]  
	        res[i] = prod % 10;  
	 
	        // Put rest in carry
	        carry  = prod/10;    
	    }
	 
	    // Put carry in res and increase result size
	    while (carry)
	    {
	        res[res_size] = carry%10;
	        carry = carry/10;
	        res_size++;
	    }
	}
	
	printf("Factorial of given number is \n");
    for (i = res_size-1; i>=0; i--)
        printf("%d",res[i]);
}
 

