/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:47:05 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:17:07 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_precision(t_table *table, const char *format, int j)
{
	long int	ret;
	int			is_prec;

	ret = 6;
	is_prec = 0;
	while (is_conversion(format, j) == 0)
	{
		if (format[j] == '.')
		{
			ret = 0;
			is_prec = 1;
		}
		if (ft_isdigit(format[j]) == 1 && is_prec == 1)
		{
			ret = ft_atol(format, j);
			break ;
		}
		++j;
	}
	if (is_prec == 0)
		return (-1);
	else
		table->cursor->zero_pad = -1;
	return (ret);
}

long int		get_precision(t_table *table, const char *format, int i)
{
	long int	ret;
	int			j;

	j = i + 1;
	ret = is_precision(table, format, j);
	return (ret);
}
