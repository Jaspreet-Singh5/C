#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct term{
	int coeff;
	int exp;
};

struct poly{
	struct term *t;
	int numOfTerms;
};

void readPoly(struct poly *);
void appendPoly(struct poly *);
void displayPoly(struct poly);
struct poly addPoly(struct poly,struct poly);
void line();
char * repeatCheck(char *);


main(){
	struct poly p1,p2,p3;
	int opt1,opt2;
	char *pos;
	
	do{
		system("cls");
		line();
		printf("Choose one of the following options: \n");
		line();
		printf("1. Input polynomials\n");
		printf("2. Append polynomials\n");
		printf("3. Display polynomials\n");
		printf("4. Addition\n");
		printf("5. Subtraction\n");
		printf("6. Multiplication\n");
		line();
		printf("Selected option: ");
		scanf("%d",&opt1);
		line();
		
		switch(opt1){
			case 1:
				line();
				printf("Enter the elements of polynomial no.1\n");
				line();
				readPoly(&p1);
				
				printf("\n\n");
				
				line();
				printf("Enter the elements of polynomial no.2\n");
				line();
				readPoly(&p2);
				break;
				
			case 2:
				again2:
				printf("\n");
				line();
				printf("Choose the desired polynomial\n");
				line();
				printf("1.Polynomial no.1   2.Polynomial no.2\n");
				line();
				printf("Selected option: ");
				scanf("%d",&opt2);
				line();
				
				switch(opt2){
					case 1:
						line();
						printf("Append the elements of polynomial no.1\n");
						line();
						appendPoly(&p1);	
						break;
					
					case 2:
						line();
						printf("Append the elements of polynomial no.2\n");
						line();
						appendPoly(&p2);	
						break;
							
					default:
						line();
						printf("Wrong input!!\n");
						line();
						goto again2;
				}
				break;
							
			case 3:
				displayPoly(p1);
				printf("\n");
				displayPoly(p2);
				break;
				
			case 4:
				p3=addPoly(p1,p2);
				displayPoly(p3);
				printf("\n");
				break;
			default:
				line();
				printf("Wrong input!!\n");
				line();
				goto again2;
		}	
		getch();
		pos = repeatCheck(pos);	
	}
	while(pos);
	free(p1.t); 
	free(p2.t);
	free(p3.t);
}

// read a polynomial
void readPoly(struct poly *p){
	int i,j;
	struct term temp;
	
	printf("Enter the number of terms: ");
	scanf("%d",&p->numOfTerms);
	line();
	
	p->t=(struct term *)calloc(p->numOfTerms,sizeof(struct term));
	
	for(i=0;i<p->numOfTerms;i++){
		printf("Enter the coefficient of term no.%d: ",i+1);
		scanf("%d",&p->t[i].coeff);
		again1:
		printf("Enter the exponent of term no.%d: ",i+1);
		scanf("%d",&p->t[i].exp); 
		for(j=0;j<i;j++){
			if(p->t[j].exp==p->t[i].exp){
				line();
				printf("Wrong input!\n");
				line();
				goto again1;
			}
		}
		line();
	}
	
	for (i = 0; i < p->numOfTerms; i++){
   		// Last i elements are already in place    
    	for (j = 0; j < p->numOfTerms-i-1; j++){
    		if(p->t[j].exp > p->t[j+1].exp){
        		  temp = p->t[j];  
				  p->t[j] = p->t[j+1];
				  p->t[j+1] = temp;
		   }	
		}  		
	}
}

// append a polynomial
void appendPoly(struct poly *p){
	int i,j,numOfAppendTerms,oldNumOfTerms;
	struct term temp;
	
	printf("Enter the number of terms to be appended: ");
	scanf("%d",&numOfAppendTerms);
	line();
	
	oldNumOfTerms = p->numOfTerms;
	
	p->numOfTerms = oldNumOfTerms + numOfAppendTerms;
	
	p->t=(struct term *)realloc(p->t,p->numOfTerms*sizeof(struct term));
	
	for(i=oldNumOfTerms;i<p->numOfTerms;i++){
		printf("Enter the coefficient of term no.%d: ",i+1);
		scanf("%d",&p->t[i].coeff);
		again3:
		printf("Enter the exponent of term no.%d: ",i+1);
		scanf("%d",&p->t[i].exp); 
		for(j=0;j<i;j++){
			if(p->t[j].exp==p->t[i].exp){
				line();
				printf("Wrong input!\n");
				line();
				goto again3;
			}
		}
		line();
	}
	
	for (i = 0; i < p->numOfTerms; i++){
   		// Last i elements are already in place    
    	for (j = 0; j < p->numOfTerms-i-1; j++){
    		if(p->t[j].exp > p->t[j+1].exp){
        		  temp = p->t[j];  
				  p->t[j] = p->t[j+1];
				  p->t[j+1] = temp;
		   }	
		}  		
	}
}

// display a polynomial
void displayPoly(struct poly p){
	int i,flag=0;
	
	for(i=0;i<p.numOfTerms;i++){
		printf("%d(x^%d)",p.t[i].coeff,p.t[i].exp);
		
		if(i!=(p.numOfTerms-1))
			printf(" + "); 
	}
	printf("\n\n");
}

// add polynomials
struct poly addPoly(struct poly p1, struct poly p2){
	int i,j,c=0,flag=0,count=0;
	struct poly p3;
	
	if(p1.numOfTerms>p2.numOfTerms){
		c=p1.numOfTerms;
	}
	else{
		c=p2.numOfTerms;
	}
	
	p3.numOfTerms=0;
	
	p3.t=(struct term *)calloc((p1.numOfTerms+p2.numOfTerms),sizeof(struct term));	
	
		
	for(i=0,j=0;i<=c;p3.numOfTerms++){
		
		
				
		if(p1.t[i].exp>=p2.t[j].exp){
			if(p1.t[i].exp==p2.t[j].exp){
				p3.t[p3.numOfTerms].coeff= p1.t[i].coeff+p2.t[j].coeff;
				p3.t[p3.numOfTerms].exp=p1.t[i].exp;
				i++;
				j++;
			}
			else{
				p3.t[p3.numOfTerms].coeff= p1.t[i].coeff;
				p3.t[p3.numOfTerms].exp=p1.t[i].exp;
				i++;
			}	
		}
		else{
			p3.t[p3.numOfTerms].coeff= p2.t[j].coeff;
			p3.t[p3.numOfTerms].exp=p2.t[j].exp;
			j++;
		}
	}
	--p3.numOfTerms;
	return p3;
}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

// repeat
char * repeatCheck(char *pos){
	char flag[10];
	system("cls");
	fflush(stdin);
	line();
	printf("Main Menu\n");
	line();
	printf("---------------------------------------------------\n");
	printf("Do you want to continue? ");
	gets(flag);
	printf("---------------------------------------------------");
	
	pos = strchr(strupr(flag), 'Y');
	return pos;
}
