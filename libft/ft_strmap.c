/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:24 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:27:18 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *out_map;
	char *out_out;

	if (!(f && s))
		return (NULL);
	if (!(out_out = ft_strnew(ft_strlen(s))))
		return (NULL);
	out_map = out_out;
	while (*s != 0)
		*out_map++ = f(*s++);
	return (out_out);
}
