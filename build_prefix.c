/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:44:17 by panderss          #+#    #+#             */
/*   Updated: 2020/08/11 15:41:30 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*build_pre_pointer(t_table *table, char *str)
{
	int		i;
	char	*prefix;

	i = 0;
	if (table->cursor->width > (long)ft_strlen(str))
	{
		prefix = ft_strnew((int)table->cursor->width - (int)ft_strlen(str));
		while (i < (int)(table->cursor->width - ft_strlen(str)))
		{
			prefix[i] = ' ';
			++i;
		}
	}
	else
		prefix = NULL;
	return (prefix);
}

char		*expand_zeros(t_table *table, int padding)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(padding);
	while (i < padding)
	{
		str[i] = '0';
		++i;
	}
	return (str);
}

char		*build_prefix(t_table *table, char *str)
{
	int		i;
	char	*prefix;

	i = 0;
	if (table->cursor->conv == 3)
		return (build_pre_pointer(table, str));
	if (table->cursor->zero_pad != 1 &&
		table->cursor->width > (long)ft_strlen(str))
	{
		prefix = ft_strnew((int)table->cursor->width - ft_strlen(str));
		while (i < (int)(table->cursor->width - ft_strlen(str)))
		{
			prefix[i] = ' ';
			++i;
		}
	}
	else if (table->cursor->zero_pad == 1 &&
			table->cursor->width > (long)ft_strlen(str))
		prefix = expand_zeros(table, (int)(table->cursor->width - \
		ft_strlen(str)));
	else
		prefix = NULL;
	return (prefix);
}
