/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:44:38 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:02:00 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_suffix(t_table *table, char *s)
{
	int		i;
	char	*suffix;

	i = 0;
	if (table->cursor->width < 0 &&
		(-1 * table->cursor->width) > (int)ft_strlen(s))
	{
		suffix = ft_strnew((int)(-1 * table->cursor->width) - ft_strlen(s));
		while (i < (int)((-1 * table->cursor->width) - ft_strlen(s)))
		{
			suffix[i] = ' ';
			++i;
		}
	}
	else
		suffix = NULL;
	return (suffix);
}
