#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
	int i, num;
	for(i = 0; i < 10; i++)
	{
		num = rand() % ( 50 - 10 + 1) + 10; // ( U - l + 1 ) + l
		printf("%d \n", num);
	}
}
