#include <stdio.h>
#include <string.h>
#include <stdlib.h>



main() {
	char *str;	
	
	str=allocateString(str);
	
	puts(str);
}

char * allocateString(char *str) {
	int i=0, n=1;
	
	str=(char *)malloc(n*sizeof(char));
	while(1) {	
		str[i]=getchar();
		
		if(str[i]=='\n'){
			str[i]='\0';
			break;
		}
			
		str=(char *)realloc(str,n*sizeof(char));
		
		i++;
	}
	
	return str;
}

