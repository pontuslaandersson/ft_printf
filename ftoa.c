/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:02 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:53:18 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ftoa(double n, long precision)
{
	char	*res;
	long	ipart;
	double	fpart;
	long	i;
	long	len;

	ipart = (long)n;
	while (n >= 1.0000000)
		n--;
	fpart = n;
	len = itoa_length(ipart) + precision + 1;
	res = ft_strnew(len + 1);
	i = longtostr(ipart, res, 0);
	if (ipart == 0)
	{
		res[0] = '0';
		++i;
	}
	if (precision != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, precision);
		longtostr((long)fpart, res + i + 1, precision);
	}
	return (res);
}
