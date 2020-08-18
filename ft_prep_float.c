/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:46:24 by panderss          #+#    #+#             */
/*   Updated: 2020/08/05 13:46:26 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double		ft_prep_float(long double n, t_table *table)
{
	long double		dec;
	int				i;

	if (n < 0)
	{
		n = n * -1.0;
		table->cursor->f_sign = -1;
	}
	dec = 0.5;
	i = table->cursor->precision;
	while (i-- > 0)
		dec = dec / 10;
	n = n + dec;
	return (n);
}
