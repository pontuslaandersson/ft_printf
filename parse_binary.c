#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef union { 
	float f; 
	struct
	{
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
	unsigned long long expo;

	//s = (char*)malloc(sizeof(char) * (33));
	//s[32] = '\0';
	sign = ft_signbit((long double)f.f);
	exp = parse_binary(f.raw.exponent, 8);
	expo = binary_to_decimal(exp);
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

/*void parse_binary(int n, int i) 
{
	char	*s;
	int		j;

	j = 0;
	s = (char*)malloc(sizeof(char) * (i + 1));
	// Prints the binary representation 
	// of a number n up to i-bits. 
	int k; 
	for (k = i - 1; k >= 0; k--) { 
		if ((n >> k) & 1) 
		{
			s[j] = '1';
			++j;
		}
		else
		{
			s[j] = '0';
			++j;
		}  
	}
	printf("string: %s\n", s);
}*/

void printBinary(int n, int i) 
{ 
	// Prints the binary representation 
	// of a number n up to i-bits. 
	int k; 
	for (k = i - 1; k >= 0; k--) { 
		if ((n >> k) & 1) 
			printf("1"); 
		else
			printf("0"); 
	} 
} 

void printIEEE(myfloat var) 
{ 
	// Prints the IEEE 754 representation 
	// of a float value (32 bits) 
	printf("%d | ", var.raw.sign); 
	printBinary(var.raw.exponent, 8); 
	printf(" | "); 
	printBinary(var.raw.mantissa, 23); 
	printf("\n"); 
}

int		main(void)
{
	myfloat var;

	var.f = -2.25; 
	// Get the IEEE floating point representation 
	printf("IEEE 754 representation of %f is : \n", 
		var.f); 
	printIEEE(var);
	//parse_binary(var.raw.exponent, 8);
	//parse_binary(var.raw.mantissa, 23);
	parse_float(var);
	var.f = 0.375; 
	// Get the IEEE floating point representation 
	printf("IEEE 754 representation of %f is : \n", 
		var.f); 
	printIEEE(var);
	parse_float(var);
	//parse_binary(var.raw.exponent, 8);
	//parse_binary(var.raw.mantissa, 23);
}