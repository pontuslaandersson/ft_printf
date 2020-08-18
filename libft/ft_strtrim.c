/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:34:48 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:34:33 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	int		i;
	int		len;
	char	*trimmed;

	if (!(str))
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	while (ft_isspace(str[len - 1]))
		len--;
	while (ft_isspace(str[i]))
		i++;
	if (len == 0)
		return (ft_strdup(""));
	if (!(trimmed = ft_strnew(len - i)))
		return (NULL);
	ft_strncpy(trimmed, str + i, len - i);
	return (trimmed);
}
