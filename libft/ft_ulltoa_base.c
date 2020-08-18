/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:20:23 by panderss          #+#    #+#             */
/*   Updated: 2020/08/07 13:20:47 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_to_base(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char		*ft_ulltoa_base(unsigned long long int n, unsigned long int base)
{
	int						i;
	char					*str;
	unsigned long long int	tmp;

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
