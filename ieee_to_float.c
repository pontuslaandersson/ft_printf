// C program to convert 
// IEEE 754 floating point representaion 
// into real value 
  
//#include <math.h> 
#include "libft.h"
#include <stdlib.h>
#include <stdio.h> 
  
typedef union { 
  
    float f; 
    struct
    { 
  
        // Order is important. 
        // Here the members of the union data structure 
        // use the same memory (32 bits). 
        // The ordering is taken 
        // from the LSB to the MSB. 
  
        unsigned int mantissa : 23; 
        unsigned int exponent : 8; 
        unsigned int sign : 1; 
  
    } raw; 
} myfloat; 

unsigned long long	ft_lltoi(const char *str)
{
	int index;
	unsigned long long n;
	unsigned long long sign;

	index = 0;
	n = 0;
	sign = 1;
	while (str[index] == ' ' || str[index] == '\n' || str[index]\
		== '\t' || str[index] == '\f' || str[index] == '\v'\
		|| str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = ((str[index] == '-') ? -1 : 1);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		n = 10 * n + (str[index] - '0');
		index++;
	}
	return ((n * sign));
}

char	*parse_binary(int n, int i) 
{
	char	*s;
	int		j;
	int k;

	j = 0;
	s = (char*)malloc(sizeof(char) * (i + 1));
	k = i - 1;
	while (k >= 0)
	{ 
		if ((n >> k) & 1) 
			s[j] = '1';
		else
			s[j] = '0';
		++j;
		k--;  
	}
	//printf("string: %s\n", s);
	s[i + 1] = '\0';
	return (s);
}

char	*parse_float(myfloat f) 
{
	char	*s;
	int		sign;
	char	*exp;
	char	*man;
	char	*tmp;
	//unsigned long long expo;

	//s = (char*)malloc(sizeof(char) * (33));
	//s[32] = '\0';
	sign = ft_signbit((long double)f.f);
	exp = parse_binary(f.raw.exponent, 8);
	//expo = binary_to_decimal(exp);
	man = parse_binary(f.raw.mantissa, 23);
	//man_binary_to_decimal(man);
	tmp = ft_strjoin(ft_itoa(sign), exp);
	free(exp);
	//free(sign);
	s = ft_strjoin(tmp, man);
	//free(tmp);
	//free(man);
	printf("string representing whole single-precision format: %s\n", s);
	return (s);
}

double				ft_pow(double n, long pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

// Function to convert a binary array 
// to the corresponding integer 
unsigned int convert_to_int(int* arr, int low, int high) 
{ 
    unsigned f = 0, i; 
    for (i = high; i >= low; i--) { 
        f = f + arr[i] * ft_pow(2, high - i); 
    } 
    return f; 
} 
 
int convert_binary_to_int(int *arr) 
{ 
  
    // Get the 32-bit floating point number 
    unsigned int ieee[32] 
        = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
	myfloat var; 
    // Convert the least significant 
    // mantissa part (23 bits) 
    // to corresponding decimal integer 
    unsigned int f = convert_to_int(ieee, 9, 31); 
	printf("Mantissa after convert_to_int: %u\n", var.raw.mantissa);
    // Assign integer representation of mantissa 
    var.raw.mantissa = f; 
  
    // Convert the exponent part (8 bits) 
    // to a corresponding decimal integer 
    f = convert_to_int(ieee, 1, 8); 
  
    // Assign integer representation 
    // of the exponent 
    var.raw.exponent = f; 
  
    // Assign sign bit 
    var.raw.sign = ieee[0]; 
  
    printf("The float value of the given IEEE-754 representation is : \n"); 
    printf("%f\n", var.f); 
}

int		main(void)
{
	myfloat var;

	var.f = 0.375;
	//int *arr;
	char *s;
	s = parse_float(var);
	printf("String returned from parse_float: %s\n", s);
	//arr = string_to_array(s)
	printf("Exponent: %u\n", var.raw.exponent);
	printf("Mantissa: %u\n", var.raw.mantissa);
	return (0);
}