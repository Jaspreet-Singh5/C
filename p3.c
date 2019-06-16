#include <stdio.h>

main() {
	char str1[30];
	char str2[30];
	int i;
	
	gets(str1);
	gets(str2);
	
	for(i=0;str1[i]!='\0';i++) {
		str2[i]=str1[i];
	}
	str2[i]='\0';
	
	for(i=i++;i<30;i++)
		str2[i]=' ';
		
	printf("\n%s",str2);
}
