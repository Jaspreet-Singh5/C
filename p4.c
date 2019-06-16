#include <stdio.h>
#include <string.h>

main() {
	char str1[30];
	char str2[30];
	int i, j;
	gets(str1);
	gets(str2);
	
	for(i=0;str1[i]!='\0';i++);
	
	for(i=i,j=0;str2[j]!='\0';i++,j++)
		str1[i]=str2[j];
	
	puts(str1);
}
