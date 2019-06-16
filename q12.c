#include <stdio.h>
#include <stdlib.h>
#include "q12_valid.h"
#include "q16.h"

main() {
	struct Node *head;
	int opt=0, n, i, x, val;
	int pos;
	head=NULL;
	struct Node *temp1;
	int count=0;
	
	line();
	printf("Program to implement doubly linked list creation, insertion and deletion");
	line();
	
	while(1) {
		int count=0;
		
		opt=(int)menu(opt);
	
		switch(opt) {
			case 1: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					
					head=insertB(head,x);
				}
				print(head);
			break;
			
			case 2: 
				n=(int)validNum();
				line();
								
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					
					head=insertE(head,x);
				}
				print(head);
			break;
			
			case 3: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					pos=(int)validPos();
					
					count=0;
					temp1=head;
					while(temp1 != NULL) {  
						count++;
						temp1 = temp1->next;
					}
					
					if(pos <= 0 || pos > count && !(pos == count+1)) {
						line();
						printf("Position is out of range");
						line();
					}
					if(pos <= 0 || pos > count && !(pos == count+1))
						continue;
						
					head=insertN(head,x,pos);
				}
				print(head);
			break;
			
			case 4: 
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					x=(int)validVal(i);
					val=(int)validValNI(i);
					
					int pos = search(head,val);
					
					if(pos != -1)
						insertN(head,x,pos+2);
						
					else {
						line();
						printf("Value not found");
						line();
					}
				}
				print(head);
			break;
			
			case 5:
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					if(getCount(head) != 0) {						
						head=deleteB(head);
						line();
						print(head);
						line();
					}
					else {
						line();
						printf("List is empty!!");
						line();
					}
				}
				
			break;
			
			case 6:
				n=(int)validNum();
				line();
				
				for(i=0;i<n;i++) {
					if(getCount(head) != 0) {
						head=deleteE(head);
						line();
						print(head);
						line();
					}
					else {
						line();
						printf("List is empty!!");
						line();
					}
				}
			break;
			
			case 7:
				if(getCount != 0) {
					pos=(int)validPos();
					
					count=getCount(head);
					
					if(pos==1) 
					head=deleteB(head);
				
					if(pos==count)
						head=deleteE(head);
					
					if(pos <= 0 || pos > count && !(pos == count+1)) {
						line();
						printf("Position is out of range");
						line();
					}
					if(pos <= 0 || pos > count && !(pos == count+1))
						break;
					
					if(pos!=1 && pos!=count)
						head=deleteN(head,pos);
					
					print(head);
				}
				else {
					line();
					printf("List is empty!!");
					line();
				}
			break;
			
			case 8:
				if(getCount(head) != 0) {
					val=(int)validValD();
					
					int pos = search(head,val);
					
					if(pos==0) 
						head=deleteB(head);
		
					if(pos != -1) {
						if (pos!=0)
							deleteN(head,pos+1);
					}
						
					else {
						line();
						printf("Value not found");
						line();
					}
					
					print(head);
				}
				else {
					line();
					printf("List is empty!!");
					line();
				}
			break;
			
			case 9:
				print(head);
			break;
			
			case 10: 
				revPrint(head);
			break;
			
			case 11: 
				exit(1);
			break;
			
			default:
				line();
				printf("Wrong input!!");
				line();
		}
	}	
}


