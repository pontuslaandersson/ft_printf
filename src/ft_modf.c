#include "libft.h"

long double     ft_modf(long double x, long double *integer)
{
	long double int_part;

	int_part = (long double)(long int)x;
	*integer = int_part;
	return (x - int_part);
}
