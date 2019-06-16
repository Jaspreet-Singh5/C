#include <stdio.h>
#include <string.h>

char * subString(char *str, int pos, int len, char *find);

main() {
	char str1[30], insert[30];

	int i, pos;
	
	gets(str1);
	
	for(i=0;str1[i]!='\0';i++);
	
	scanf("%d",&pos);
	
	char strR[30];
	char strL[30];
	
	subString(str1,0,pos-1,strR);
	subString(str1,pos,i,strL);
	
	fflush(stdin);
	gets(insert);
	
	strcat(strR,insert);
	strcat(strR,strL);
	
	puts(strR);
}

char * subString(char *str, int pos, int len, char *find) {
	int i,j;
	
	for(i=pos,j=0;i<=pos+len;i++,j++){
		find[j] = str[i];  
	}	
}


