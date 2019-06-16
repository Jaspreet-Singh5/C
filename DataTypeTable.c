/* To print a table of datatypes */
/* Coded by Jaspreet Singh */
#include <stdio.h>
/*Main function starts*/
main()
{
	/* declare different types of variables */
	char c;
	unsigned char hhu;
	int i;
	unsigned int u;
	short int hi;
	unsigned short int hu;
	long int li;
	unsigned long int lu;
	float f;
	double lf;
	long double Lf;
	/* print a message */
	printf("    Access Specifier        Size \n");
	printf("         char                %d \n",sizeof(c));
	printf("     unsigned char           %d \n",sizeof(hhu));
	printf("         int                 %d \n",sizeof(i));
	printf("     unsigned int            %d \n",sizeof(u));
	printf("      short int              %d \n",sizeof(hi));
	printf("    unsigned short int       %d \n",sizeof(hu));
	printf("       long int              %d \n",sizeof(li));
	printf("     unsigned long int       %d \n",sizeof(lu));
	printf("         float               %d \n",sizeof(f));
	printf("        double               %d \n",sizeof(lf));
	printf("      long double            %d \n",sizeof(Lf));
}
/* Main function ends */
























