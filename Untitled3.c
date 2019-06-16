#include<stdio.h>
#define TEMP 10

#ifdef TEMP
  #undef TEMP
  #define TEMP 75
#else
  #define TEMP 100
#endif

int main()
{
   printf("%d",TEMP);
   getch();
return 0;
}

