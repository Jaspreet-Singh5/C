#include <stdio.h>
#include <math.h>

int main(){
	int t, n[108], i, j;
	scanf("%d", &t);
	
	for(i = 0; i < t && t <= pow(10, 5); i++)
	    scanf("%d", &n[i]);
	printf("\n\n");
	for(j = 0; j < i; j++)
	{
	    if(n[j] >= 108 || n[j] <= 1)
	        printf("Out of constraint");
	    
	    if(n[j] < 13)
	        printf("%d\n", (13 - n[j]));
	    else if(n[j]<25)
	        printf("%d\n", (37 - n[j]));
	    else if(n[j]<37)
	        printf("%d\n", (61 - n[j]));
	    else if(n[j]<49)
	        printf("%d\n", (85 - n[j]));
	    else if(n[j]<61)
	        printf("%d\n", (109 - n[j]));
	    else if(n[j]<73)
	        printf("%d\n", (133 - n[j]));
	    else if(n[j]<85)
	        printf("%d\n", (157 - n[j]));
	    else if(n[j]<97)
	        printf("%d\n", (181 - n[j]));
	    else if(n[j]<=108)
	        printf("%d\n", (205 - n[j]));
	}
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here

