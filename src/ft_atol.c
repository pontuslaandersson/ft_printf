/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:46:13 by panderss          #+#    #+#             */
/*   Updated: 2020/08/05 13:46:14 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *str, long int start)
{
	long int index;
	long int n;
	long int sign;

	index = start;
	n = 0;
	sign = 1;
	while (str[index] == ' ' || str[index] == '\n' || str[index]\
		== '\t' || str[index] == '\f' || str[index] == '\v'\
		|| str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = ((str[index] == '-') ? -1 : 1);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		n = 10 * n + (str[index] - '0');
		index++;
	}
	return ((n * sign));
}
