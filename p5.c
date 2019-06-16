#include <stdio.h>
#include <string.h>

main() {
	char str1[30];
	char find[30];
	int i, pos, len, j;
	
	gets(str1);
	
	scanf("%d",&pos);
	scanf("%d",&len);
	
	for(i=pos,j=0;i<pos+len;i++,j++){
		find[j] = str1[i];  
	}
	
	puts(find);
}
