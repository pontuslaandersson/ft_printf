/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:39:59 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 12:58:05 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *sone;
	unsigned char *stwo;

	sone = (unsigned char*)s1;
	stwo = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*sone == *stwo && n-- > 0)
	{
		sone++;
		stwo++;
		if (n == 0)
			return (0);
	}
	if (*sone != *stwo)
	{
		return (*sone - *stwo);
	}
	return (0);
}
