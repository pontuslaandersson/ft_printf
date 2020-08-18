#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%f\n", -0);
	printf("%f\n", -0);
	ft_printf("%f\n", -0.);
	printf("%f\n", -0.);
	return (0);
}