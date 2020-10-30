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
#include <stdio.h>

char				*longtostr(long nb, long decimals, int len)
{
	//long i;

	//i = len;
	//ft_putnbr(len);
	//ft_putendl(" <= len sent to longtostr.");
	//printf("nb = %ld\n", nb);
	char *tmp;
	char *str;

	tmp = ft_strnew(len);
	if (decimals == 0 && nb == 0)
	{
		tmp[0] = '0';
		len--;
	}
	while (nb && len >= 0)
	{
		//ft_putendl("Doing longtostr loop.");
		tmp[len-- - 1] = (nb % 10) + '0';
		//write(1, &tmp[len], 1);
		//ft_putendl(" <= character put into string.");
		//ft_printf("%ld", (nb % 10) + '0');
		//ft_putendl(" <= number of character put into string.");
		//ft_putnbr(len);
		//ft_putendl(" <= inserting at this position");
		//ft_putchar((nb % 10) + '0');
		//ft_putendl("<= character for digit.");
		nb = nb / 10;
	}
	if (len != 0)
	{
		while (len >= 0)
		{
			tmp[len-- - 1] = '0';
			//ft_putendl("Placed a zero.");
		}
	}
	//while (i < decimals)
		//str[i++] = '0';
	//str[i] = '\0';
	//ft_strrev(str, i);
	str = ft_strdup(tmp);
	//ft_strdel(&tmp);
	//ft_putstr("str: ");
	//ft_putendl(str);
	return (str);
}
