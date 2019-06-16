#include <stdio.h>
#include <math.h>

int main()
{
    int number, originalNumber, remainder, result = 0, n = 0 ;

    printf("Enter an integer: ");
    scanf("%d", &number);

     originalNumber = number;
    
    do
	{
        originalNumber /= 10;
        ++n;
    }
    while (originalNumber != 0);
    
	originalNumber = number;
	
	do
    {
        remainder = originalNumber%10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }
	while (originalNumber != 0);
    
    if(result == number)
        printf("%d is an Armstrong number.", number);
    else
        printf("%d is not an Armstrong number.", number);

    return 0;
}
