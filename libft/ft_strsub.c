/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:55:13 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:34:07 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*out;
	char		*str;
	char const	*src;

	if (s)
	{
		str = ft_strnew(len);
		out = str;
		src = &s[start];
		if (str)
		{
			while (*src != 0 && len > 0)
			{
				*str++ = *src++;
				len--;
			}
			return (out);
		}
		else
		{
			return (NULL);
		}
	}
	else
		return (NULL);
}
