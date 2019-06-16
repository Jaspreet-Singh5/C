// Program to copy the elements of one array into another
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

main()
{
	char a[50], b[50], flag, *pos;
	int i, j;
	
	printf("-------------------------------------------------------- \n");
	printf(" Program to copy the elements of one array into another \n");
	printf("-------------------------------------------------------- \n\n");	
	
	printf("------------------------------------------------------------------------------------------ \n");
	printf(" Enter the elements of first array: ");
	gets(a);
	printf("------------------------------------------------------------------------------------------ \n");
	
	for(i = 0; i == 0 || !(a[i  - 1] == '\0'); i++)
		b[i] = a[i];
	
	printf("------------------------------------------------------------------------------------------ \n");
	printf(" The copied string is: %s \n", b);
	printf("------------------------------------------------------------------------------------------ \n");
}
