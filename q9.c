#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringManipulation.h"

main() {
	char *str1, *str2, *str3;
	int i, len, flag, flag1;
	int opt=0, opt1=0, opt2=0;
	
	line();
	printf("Program to compare, concatenate, copy strings and find the length of a string");
	line();
	
	while(1) {
		int opt=(int)menu(opt);
	
		switch(opt) {
			case 1:
				line();
				printf("Enter the string no.1: ");
				str1=allocateString(str1);
				
				printf("Enter the string no.2: ");
				str2=allocateString(str2);
				
				line();	
				
				flag=1;
				break;
			
			case 2:
				if(flag==1){
				
				opt2=(int)subMenu(opt2);
				
				switch(opt2) {
					case 1:
						line();
						printf("Length of string no.1: %d",strlen(str1));
						printf("\nLength of string no.2: %d",strlen(str2));
						line();
					break;
					
					case 2:
						line();
						printf("Copied string no.1: %s",strcpy(str1,str2));
						line();
					break;
			
					case 3:
						line();
						printf("Concatenated string no.1: %s",strcat(str1,str2));
						line();
					break;
					
					case 4:
						flag=strcmp(str1,str2);
						
						if(flag>1){
							line();
							printf("String no.1 is greater than string no.2.");
							line();		
						}
						
						else if(flag<1){
							line();
							printf("String no.2 is greater than string no.1.");
							line();		
						}
						
						else {
							line();
							printf("Strings are equal.");
							line();		
						}
					break;
				}
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
			
			case 3:
				if(flag==1){
				opt1=(int)subMenu(opt1);
				
				switch(opt1) {
					case 1:
						line();
						printf("Length of string no.1: %d",strLen(str1));
						printf("\nLength of string no.2: %d",strLen(str2));
						line();
					break;
					
					case 2:
						if(strlen(str2)<1){
							line();
							printf("Empty String to be copied!!");
							line();
						}
						
						if(strlen(str2)<1){
							break;
						}
						line();
						printf("Copied string no.1: %s",strCpy(str1,str2));
						line();
					break;
			
					case 3:
						if(strlen(str2)<1){
							line();
							printf("Empty String to be concatenated!!");
							line();
						}
						
						if(strlen(str2)<1){
							break;
						}
						line();
						printf("Concatenated string no.1: %s",strConcat(str1,str2));
						line();
					break;
					
					case 4:
						line();
						strCmp(str1,str2);
						line();
					break;
				}
				}
				else {
					line();
					printf("Empty String!!");
					line();
				}
			break;
							
			case 4:
				exit(0); 
		}
	}
}


