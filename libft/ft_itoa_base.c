/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:51:05 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:51:21 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		convert_to_base(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(unsigned long int n, unsigned long int base)
{
	int						i;
	char					*str;
	unsigned long int		tmp;

	i = 0;
	tmp = n;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	str = ft_strnew(i);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = n % base;
		str[i] = convert_to_base(tmp);
		n = n / base;
		i--;
	}
	return (str);
}
