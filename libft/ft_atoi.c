/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:13:41 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 12:38:28 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int index;
	int n;
	int sign;

	index = 0;
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
