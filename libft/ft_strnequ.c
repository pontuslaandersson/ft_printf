/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:42:43 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:30:27 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int result;

	if (s1 && s2)
	{
		result = ft_strncmp(s1, s2, n);
		if (result == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
