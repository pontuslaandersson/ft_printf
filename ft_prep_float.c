/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:46:24 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:46:56 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static long double	ft_modf(long double x, long double *integer)
{
	long double int_part;

	int_part = (long double)(long int)x;
	*integer = int_part;
	//printf("%Lf\n", (x - int_part));
	return (x - int_part);
}

static long double	rounding(long double nb, int precision)
{
	long double	rounding;
	long double i_part;

	ft_modf(nb, &i_part);
	rounding = precision == 0 && (int)i_part % 2 == 0 ? 0.499 : 0.500;
	if (nb == 0)
		return (nb);
	if (nb < 0)
		rounding *= -1;
	while (precision-- > 0)
		rounding /= 10.0;
	return (rounding);
}

double		ft_prep_float(long double n, t_table *table)
{
	long double		dec;
	int				i;
	/*long double		copy;
	double			fpart;
	long			len;*/

	n = n + rounding(n, table->cursor->precision);
	/*while (copy >= 1.0000000)
		copy--;
	fpart = n;*/
	if (n < 0)
	{
		n = n * -1.0;
		table->cursor->f_sign = -1;
	}
	/*dec = 0.5;
	i = table->cursor->precision;
	while (i-- > 0)
		dec = dec / 10;
	n = n + dec;*/
	return (n);
}
