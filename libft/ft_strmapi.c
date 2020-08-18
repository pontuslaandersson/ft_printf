/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:53:43 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:27:44 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	if (!(f && s))
		return (NULL);
	if (!(out = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != 0)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
