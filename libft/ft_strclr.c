/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:33:51 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:18:47 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *str)
{
	int	index;

	if (str)
	{
		index = 0;
		while (str[index] != '\0')
		{
			str[index] = '\0';
			index++;
		}
	}
}
