/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:54:13 by panderss          #+#    #+#             */
/*   Updated: 2020/08/12 14:36:51 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts a given long x to string str[].
** d is the number of digits required in the output.
** If d is more than the number of decimals in x,
** then 0s are added at the beginning.
*/

#include "ft_printf.h"

long				longtostr(long nb, char *str, long decimals)
{
	long i;

	i = 0;
	while (nb)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (i < decimals)
		str[i++] = '0';
	str[i] = '\0';
	ft_strrev(str, i);
	return (i);
}
