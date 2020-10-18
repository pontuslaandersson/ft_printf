#include <stdio.h>
 
void main()
{
    unsigned int  num, binary_val, decimal_val = 0, base = 1, rem;
 
    //printf("Enter a binary number(1s and 0s) \n");
    //scanf("%d", &num); /* maximum five digits */
    num = 1111101;
	binary_val = num;
    while (num > 0)
    {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
    printf("The Binary number is = %u \n", binary_val);
    printf("Its decimal equivalent is = %u \n", decimal_val);
}