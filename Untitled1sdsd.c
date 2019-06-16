#include <stdio.h>
#include <string.h>
main()
{
	char name[20], str[20];
	int i,j;
	gets(name);
	
	for(i=0,j=0;name[i] != '\0';i++,j++) 
	{
		if(name[i] != ' ')
			str[j] = name[i];
		else 
			--j;
	 } 
	 
	 puts(str);
}
