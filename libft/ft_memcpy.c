/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:45:37 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 12:58:57 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char *a;
	char *b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (char*)src;
	b = (char*)dst;
	while (len--)
		*b++ = *a++;
	return (dst);
}
