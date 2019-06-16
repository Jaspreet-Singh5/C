#include<stdio.h>
#include<conio.h>
main()
{
      char *str="Hello";
      char *pstr;
      pstr=str;
      while(*pstr!='\0')
      {
                        printf("%c",*pstr);
                        pstr++;
                        }
                        getch();
                        }


