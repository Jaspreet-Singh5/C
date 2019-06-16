#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct term
{
    int exp;
    float coeff;
}term;

typedef struct poly
{
    term *a;
    int n;
}poly;

void initialize(poly *ptr);
void readPoly(poly *ptr);
void printPoly(poly *ptr);
poly addPoly(poly *p1,poly *p2);
poly multiplyPoly(poly *p1,poly *p2);
float evaluatePoly(poly *p1,float x);
void insertPoly(poly *,term);
void line();

main()
{
    poly P1,P2,P3;
    int opt1,opt2,count=0;
    float x,value;
    do
    {
    	system("cls");
    	line();
    	printf("Program to demonstrate Polynomial Representation and operations \n");
    	line();
    	printf("\n\n");
    	line();
    	printf("Choose one of the following options\n");
    	line();
        printf("1. Read polynomials");
        printf("\n2. Display polynomials");
        printf("\n3. Addition");
        printf("\n4. Multiplication");
        printf("\n5. Evaluation");
        printf("\n6. Exit\n");
        line();
        printf("\nSelected option: ");
        scanf("%d",&opt1);
        line();
        
        switch(opt1)
        {
            case 1:
            	printf("\n");
				printf("\n");
				
				line();
				printf("Polynomial no.1\n");
				line();
				readPoly(&P1);
				line();
				printf("\n");
				line();
				printf("Polynomial no.2\n");
				line();
				readPoly(&P2);
				line();
				
				count++;
				
				break;
			
			case 2:
				if(count==0)
            		break;
            	
				printf("\n");
				printf("\n");
				
				line();
				printf("Polynomial no.1");
				printPoly(&P1);
				printf("\n");
				line();
				printf("Polynomial no.2");
				printPoly(&P2);
				getch();
				break;
					
            case 3:
            	if(count==0)
            		break;
            		
				P3=addPoly(&P1,&P2);
				printf("\n\n");
				line();
                printf("Polynomial no.1 is: ");
	            printPoly(&P1);
	            printf("Polynomial no.2 is: ");
	            printPoly(&P2);
	            printf("Sum of the given polynomials is: ");
	            printPoly(&P3);
	            getch();
	            break;
            
            case 4:
				if(count==0)
            		break;
            		
				P3=multiplyPoly(&P1,&P2);
				printf("\n\n");
				line();
                printf("Polynomial no.1 is: ");
                printPoly(&P1);
                printf("Polynomial no.2 is: ");
                printPoly(&P2);
                printf("Product of the given polynomials is: ");
                printPoly(&P3);         
                getch();
				break;
            
			case 5:
				if(count==0)
            		break;
            		
            	printf("\n\n");
				line();
				printf("Enter the value of x: ");
                scanf("%f",&x);
                line();
                
                line();
                printf("Choose the polynomial to be evaluated\n");
                line();
                printf("1. Polynomial no.1   2. Polynomial no.2\n");
                line();
                printf("Selected option: ");
                scanf("%d",&opt2);
                line();
                
                if(opt2==1)
                	value=evaluatePoly(&P1,x);
                else if(opt2==2)
                	value=evaluatePoly(&P2,x);
                else{
                	printf("\n");
                	line();
                	printf("Wrong input!!\n");
                	line();
                	getch();
				}
				
				if(opt2!=1&&opt2!=2)
					break;
                
				line();	
                printf("Value of the polynomial is: %6.2f\n",value);
                line();
				getch();
				break;
			
			case 6:
				exit(0);
				break;
				
			default:
				printf("\n");
				line();
	        	printf("Wrong input!\n");
	        	line();
	        	getch();		
        }
        
        if(count==0 && opt1>=1 && opt1<=6){
        	printf("\n");
			line();
        	printf("No polynomial found!\n");
        	line();
        	getch();
		}
				
    }while(opt1!=7);
    free(P1.a);
    free(P2.a);
}

void readPoly(poly *Ptr)
{
    int n, i, exp;
    float coeff;
    term t;
    initialize(Ptr);
    
	do{
    	line();
		printf("Enter number of terms: ");
	    scanf("%d",&n);
	    line();
		
		if(!(n>0)){
			printf("\n");
			line();
			printf("Number of terms can not be negative!!\n");
			line();
		}	
	}
	while(!(n>0));
	

 	
    /* read n terms */
    for (i=0;i<n;i++)
    {   printf("Enter a term(coeff. exp): ");
        scanf("%f%d",&coeff,&exp);
        t.exp=exp;
        t.coeff=coeff;
        insertPoly(Ptr,t);
    }
}

void printPoly(poly *Ptr)
{
    int i;
    printf("\n");
	line();
	printf("%5.2f(x^%d) ",(Ptr->a[0]).coeff,(Ptr->a[0]).exp);
    for(i=1;i<Ptr->n;i++)
      printf(" + %5.2f(x^%d) ",(Ptr->a[i]).coeff,(Ptr->a[i]).exp);
    printf("\n");
    line();
}

poly addPoly(poly *P1, poly *P2)
{
    poly P3;
    term t;
    int i,j;
    i=j=0;
    initialize(&P3);
    while(i<P1->n && j<P2->n)
    {
        if(P1->a[i].exp==P2->a[j].exp)
        {
            t.exp=P1->a[i].exp;
            t.coeff=P1->a[i].coeff+P2->a[j].coeff;
            insertPoly(&P3,t);
            i++;j++;
        }
        else if(P1->a[i].exp < P2->a[j].exp)
        {
            insertPoly(&P3,P1->a[i]);
            i++;
        }
        else
        {
            insertPoly(&P3,P2->a[j]);
            j++;
        }
    }
    return(P3);
}


poly multiplyPoly(poly *P1,poly *P2)
{
    poly P3, Ptemp;
    term t;
    int i,j;
    initialize(&P3);
    for(i=0;i<P2->n;i++)
    {
        initialize(&Ptemp);
        for(j=0;j<P1->n;j++)
        {
            t.exp=P1->a[j].exp+P2->a[i].exp;
            t.coeff=P1->a[j].coeff*P2->a[i].coeff;                                        
			insertPoly (&Ptemp, t);
        }
    P3=addPoly(&P3,&Ptemp);
    }
    return(P3);
}

float evaluatePoly(poly *P, float x)
{
    float value;
    int i,power;
    value=0.00;
    for(i=0;i<P->n;i++)
     { power=P->a[i].exp;
    value += (P->a[i].coeff)*pow(x,power);
      }
    return(value);
}

void initialize(poly *Ptr)
{
    Ptr->n=0;
	
	Ptr->a=(term *)calloc(1,sizeof(term));
 	if(Ptr->a == NULL)
 		printf("Unable to allocate space");
}

void insertPoly(poly *Ptr,term t)
{
    int i;
    
    if(Ptr->n!=0){
    	Ptr->a=(term *)realloc(Ptr->a,((Ptr->n)+1)*sizeof(term));
	 	if(Ptr->a == NULL)
	 		printf("Unable to allocate space");
	}
	/* move all higher exp term by 1 place.
	   movement should start with the last term */
    for(i=Ptr->n-1; (Ptr->a[i]).exp > t.exp && i>=0;i--)
        Ptr->a[i+1]=Ptr->a[i];
    /* insert the term t */
    Ptr->a[i+1]=t;
    (Ptr->n)++;
}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}
