/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:14:56 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:32:06 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int position;

	position = ft_strlen(str);
	if (str)
	{
		while (str[position] != (char)c && position >= 0)
			position--;
		if (str[position] == (char)c)
			return ((char*)&str[position]);
		else
			return (NULL);
	}
	return (NULL);
}
