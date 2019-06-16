#include <stdio.h>

typedef struct{
	char name[20];
	int no;
}student;

void input(student *sp);
void output(student sp);
  
main()
{
	int i = 0;
	student s[5];
	
	for(i = 0;i<5;i++)
	{
		input(&s[i]);
	}
	
	for(i = 0;i<5;i++)
	{
	output(s[i]);
	}
}

void input(student *sp)
{
	fflush(stdin);
	scanf("%[^\n]",&sp->name);
	scanf("%d",&sp->no);
}

void output(student sp)
{
	
	printf("%s \n",sp.name);
	printf("%d \n",sp.no);
	
}
