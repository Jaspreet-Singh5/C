#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
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

main()
{
    poly P1,P2,P3;
    int opt1;
    float x,value;
    do
    {
        printf("\n1 : Create 1'st polynomial");
        printf("\n2 : Create 2'nd polynomial");
        printf("\n3 : Add polynomials");
        printf("\n4 : Multiply polynomials");
        printf("\n5 : Evaluate 1'st polynomial");
        printf("\n6 : Quit");
        printf("\nEnter your choice :");
        scanf("%d",&opt1);
        switch(opt1)
        {
            case 1:
				readPoly(&P1);
				break;
            case 2:
				readPoly(&P2);
				break;
            case 3:
				P3=addPoly(&P1,&P2);
                printf("\n1'st polynomial -> ");
	            printPoly(&P1);
	            printf("\n2'nd polynomial -> ");
	            printPoly(&P2);
	            printf("\n Sum = ");
	            printPoly(&P3);
	            break;
            case 4:
				P3=multiplyPoly(&P1,&P2);
                printf("\n1'st polynomial -> ");
                printPoly(&P1);
                printf("\n2'nd polynomial -> ");
                printPoly(&P2);
                printf("\n Product = ");
                printPoly(&P3);
                break;
            case 5:
				printf("\nEnter the value of x:");
                scanf("%f",&x);
                value=evaluatePoly(&P1,x);
                printf("\nValue of Polynomial =%6.2f",value);
                break;
        }
    }while(opt1!=6);
}

void readPoly(poly *Ptr)
{
    int n, i, exp;
    float coeff;
    term t;
    initialize(Ptr);
    printf("\n Enter number of terms :");
    scanf("%d",&n);
    
	Ptr->a=(struct term *)calloc(n,sizeof(int));
	
    /* read n terms */
    for (i=0;i<n;i++)
    {   printf("\nEnter a term(exp  coeff.)");
        scanf("%d%f",&exp,&coeff);
        t.exp=exp;
        t.coeff=coeff;
        insertPoly(Ptr,t);
    }
}
void printPoly(poly *Ptr)
{
    int i;
    printf("%5.2f(x^%d) ",(Ptr->a[0]).coeff,(Ptr->a[0]).exp);
    for(i=1;i<Ptr->n;i++)
      printf(" + %5.2f(x^%d) ",(Ptr->a[i]).coeff,(Ptr->a[i]).exp);
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
        else
            if(P1->a[i].exp < P2->a[j].exp)
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
    while(i<P1->n)
    {
         insertPoly(&P3,P1->a[i]);
         i++;
    }
    while(j<P2->n)
    {
         insertPoly(&P3,P2->a[j]);
         j++;
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
    int i,exp;
    value=0.00;
    for(i=0;i<P->n;i++)
     { exp=P->a[i].exp;
    value=value+(P->a[i].coeff)*pow(x,exp);
      }
    return(value);
}

void initialize(poly *Ptr)
{
    Ptr->n=0;
}

void insertPoly(poly *Ptr,term t)
{
    int i;
    /* move all higher exp term by 1 place.movement
       should start with the last term */
    for(i=Ptr->n-1; (Ptr->a[i]).exp > t.exp && i>=0;i--)
        Ptr->a[i+1]=Ptr->a[i];
    /* insert the term t */
    Ptr->a[i+1]=t;
    (Ptr->n)++;
}
