/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:14:49 by panderss          #+#    #+#             */
/*   Updated: 2020/08/03 14:59:07 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*duplicate;
	int		index;

	index = 0;
	while (src[index])
		index++;
	if (!(duplicate = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = -1;
	while (src[++index] != '\0')
		duplicate[index] = src[index];
	duplicate[index] = '\0';
	return (duplicate);
}
