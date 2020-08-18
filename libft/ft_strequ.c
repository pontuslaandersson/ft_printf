/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:35:29 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:24:02 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	int result;

	if (s1 && s2)
	{
		result = ft_strcmp(s1, s2);
		if (result == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
