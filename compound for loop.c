// Demonstration of compound for loop
#include <stdio.h>
main()
{
	int m, n, p, result;
	printf("	M	N	P	Result \n");
	for(m = 0, n =0, p = 2; m <= 6; m++, n += 2, p++)
	{
		result = m * n * p;
		printf("	%d	%d	%d	%d  \n", m, n, p, result);
	}
}
