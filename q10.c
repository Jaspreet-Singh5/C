#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double menu(int);
char * allocateString(char *str);
char * subString(char *, int, int);
void naiveSearch(char *, char *, int *);
void kmpSearch(char *, char *, int *);
void lpsArray(char *, int *);
void line();

main() {
	char *str1, *find, *pat;
	int i, flag[]={0,0,0}, pos, len, count1=0, count2=0;
	int opt=0, opt1=0, opt2=0;
	
	char bestTN[]={'A','A','B','C','C','A','A','D','D','E','E'}, bestPN[]={'F','A','A'}, worstTN[]={'A','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A','A'}, worstPN[]={'A','A','A','A','A'};
	int cBN=0, cWN=0, cBKMP=0, cWKMP=0;
	
	
	line();
	printf("Program to do pattern matching in a string");
	line();
	
	while(1) {
		int opt=(int)menu(opt);
	
		switch(opt) {
			case 1:
				line();
				printf("Enter the string no.1: ");
				str1=allocateString(str1);
				line();	
				
				flag[0]=1;
				break;
			
			case 2:
				if(flag[0]==1){
					if(strlen(str1)<1){
						line();
						printf("Empty string!!");
						line();
					}
					if(strlen(str1)<1){
						break;
					}
					line();
					printf("Enter the pattern string: ");
					pat=allocateString(pat);
					line();
					if(strlen(pat)<1){
						line();
						printf("Empty string!!");
						line();
					}
					if(strlen(pat)<1){
						break;
					}
					
					naiveSearch(str1,pat,&count1);
					
					flag[1]=1;
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
			
			case 3:
				if(flag[0]==1){
					if(strlen(str1)<1){
						line();
						printf("Empty string!!");
						line();
					}
					if(strlen(str1)<1){
						break;
					}
					line();
					printf("Enter the pattern string: ");
					pat=allocateString(pat);
					line();
					
					if(strlen(str1)<1){
						line();
						printf("Empty string!!");
						line();
					}
					if(strlen(str1)<1){
						break;
					}
					
					kmpSearch(str1,pat,&count2);
					flag[2]=1;
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
				
			case 4:
				if(flag[0]==1){
					line();
					printf("Enter the position number: ");
					scanf("%d",&pos);
					printf("Enter the length of the substring: ");
					scanf("%d",&len);
					
					if(len<1){
						line();
						printf("Empty string!!");
						line();
					}
					if(len<1){
						break;
					}
					
					find=subString(str1,pos,len);
					
					printf("The required substring is: %s",find);	
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
				
			case 5:
				if(flag[0]==1){
					if(flag[1]==1 && flag[2]==1){
						line();
						printf("No. of comparisons in case of naive search algorithm: %d\n",count1);
						printf("No. of comparisons in case of kmp search algorithm: %d",count2);
						line();
					}
					else{
						line();
						printf("You should do the pattern searching first!!");
						line();
					}
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
			
			case 6:
				naiveSearch(bestTN,bestPN,&cBN);
				naiveSearch(worstTN,worstPN,&cWN);
				kmpSearch(bestTN,bestPN,&cBKMP);
				kmpSearch(worstTN,worstPN,&cWKMP);
				
				line();
				printf("No. of comparisons in best case of naive search algorithm: %d\n",cBN);
				printf("No. of comparisons in best case of kmp search algorithm: %d\n",cBKMP);
				printf("No. of comparisons in worst case of naive search algorithm: %d\n",cWN);
				printf("No. of comparisons in worst case of kmp search algorithm: %d",cWKMP);
				line();
			break;		
			case 7:
				exit(0); 
		}
	}
}

// main menu
double menu(int opt2){
	double opt1=-1;
	char input[80]; // arbitrary size buffer
    char* cp, badc; // badc is for detecting extraneous chars in the input
    int n;
    
	printf("\n\n");
	line();
	printf(" Choose one of the following options");
	line();
	printf("1. Read a string\n");
	printf("2. Naive/Brute force pattern searching\n");
	printf("3. KMP pattern searching\n");
	printf("4. Substring\n");
	printf("5. Display the performance of naive and kmp pattern searching\n");
	printf("6. Best and Worst case performance\n");
	printf("7. Exit");
	line();
	if(!(opt2==1||opt2==3)||(opt2==4)||(opt2==5)||(opt2==6)){
		printf("Selected option: ");	
	}
	while (opt1 < 1 || opt1>7)
    {
        cp = fgets(input, sizeof(input), stdin);
        if (cp == input)
        {
        	n = sscanf(input, "%lf %c", &opt1, &badc);
			if (n != 1) // if badc captured an extraneous char
            {	if((opt2==1||opt2==3||opt2==4)){
					printf("Selected option: ");
				}
				else
					printf("Please enter a number: ");
                opt1 = -1;
            }
            else if (opt1 < 0)
                printf("Error! Please enter a POSITIVE number: ");
            
	    	else if(opt1>7){
	    		line();
	    		printf("Wrong input!!\n");
	    		line();
	    	}
        }
    }
	
	
	line();
	printf("\n");	
	
	
	return opt1;
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
		n++;	
		str=(char *)realloc(str,n*sizeof(char));
		
		i++;
	}
	
	return str;
}

void naiveSearch(char *str, char *pat, int *c) {
	int n=strlen(str);
	int m=strlen(pat);
	
	int i,j, flag=0;
	
	line();
	printf("Text - Pattern");
	line();
	for(i=0;i<=n-m;i++){
		for(j=0;j<m;j++){
			printf("%c\t%c\n",str[i+j],pat[j]);
			*c=*c+1;
			if(str[i+j] != pat[j]){
				break;		
			}
		}
		
		if(j==m){
			line();
			printf("Pattern found at index: %d",i);
			line();
			
			flag=1;
		}
	}
	
	if(flag==0){
		line();
		printf("Sorry! no match found.");
		line();
	}
}

void kmpSearch(char *str, char *pat, int *c) {
	int n=strlen(str);
	int m=strlen(pat);
	int i=0,j=0, flag=0;
	int lps[m];
	
	lpsArray(pat,lps);
	
	line();
	printf("Text - Pattern");
	line();
	while(i<n) {
		
		printf("%c\t%c\n",str[i],pat[j]);
		*c=*c+1;
		
		if(pat[j]==str[i]) {
			j++;
			i++;
		}
		
		if(j==m) {
			line();
			printf("Pattern found at index: %d",i-j);
			line();
			
			j=lps[j-1];
			
			flag=1;
		}
		
		else if(i<n && pat[j]!=str[i]) {
			if(j!=0)
				j=lps[j-1];
			
			else
				i++;
		}
	}
	
	if(flag==0){
		line();
		printf("Sorry! no match found.");
		line();
	}
}

void lpsArray(char *pat, int *lps) {
	int m=strlen(pat);
	int len=0;
	lps[0]=0;
	
	int i=1;
	while(i<m) {
		if(pat[i] == pat[len]) {
			len++;
			lps[i]=len;
			i++;
		}
		
		else{
			if(len!=0){
				len=lps[len-1];
			}
			
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

char * subString(char *str, int pos, int len) {
	int i,j;
	char *find;
	for(i=pos,j=0;i<pos+len && i<strlen(str);i++,j++){
		if(j==0)
			find=(char *)malloc(1*sizeof(char));
		else
			find=(char *)realloc(find,(j+2)*sizeof(char));
			
		find[j] = str[i];  
	}	
	find=(char *)realloc(find,(j+1)*sizeof(char));
	find[j]='\0';
	
	return find;
}

// line
void line(){
	int i;
	printf("\n");
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}
