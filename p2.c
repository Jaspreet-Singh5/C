#include <stdio.h>
#include <string.h>

main() {
	char str[30];
	int i;
	
	gets(str);
	
	for(i=0;str[i]!='\0';i++);
	
	printf("%d",i);
}
