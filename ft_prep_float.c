/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:46:24 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:45:38 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_modf(long double x, long double *integer)
{
	long double int_part;

	int_part = (long double)(long int)x;
	*integer = int_part;
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

double				ft_prep_float(long double n, t_table *table)
{
	n = n + rounding(n, table->cursor->precision);
	if (n < 0)
	{
		n = n * -1.0;
		table->cursor->f_sign = -1;
	}
	return (n);
}
