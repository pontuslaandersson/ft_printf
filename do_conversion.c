/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:42 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:54:25 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			actual_c_conversion(t_table *table)
{
	char		*prefix;
	char		*suffix;
	char		*tmp;

	prefix = build_prefix(table, table->cursor->argument);
	if (prefix)
	{
		tmp = ft_strjoin(prefix, table->cursor->argument);
		free(table->cursor->argument);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(prefix);
	}
	suffix = build_suffix(table, table->cursor->argument);
	if (suffix)
	{
		tmp = ft_strjoin(table->cursor->argument, suffix);
		free(table->cursor->argument);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(suffix);
	}
	return (ft_strlen(table->cursor->argument));
}

size_t			c_conversion(t_table *table)
{
	int			c;
	size_t		len;

	c = va_arg(table->args, int);
	table->cursor->argument = ft_strnew(1);
	table->cursor->argument[0] = c;
	if (c == 0)
		len = nul_c_conversion(table);
	else
		len = actual_c_conversion(table);
	table->cursor->len = len;
	return (table->cursor->len);
}

size_t			percent_conversion(t_table *table)
{
	size_t		len;

	table->cursor->argument = ft_strnew(1);
	table->cursor->argument[0] = '%';
	len = actual_c_conversion(table);
	table->cursor->len = len;
	return (len);
}

size_t			do_conversion(t_table *table, int conv)
{
	size_t		len;

	if (conv == 1)
		len = s_conversion(table);
	if (conv == 2)
		len = c_conversion(table);
	if (conv == 3)
		len = p_conversion(table);
	if (conv == 4)
		len = d_conversion(table);
	if (conv == 5)
		len = d_conversion(table);
	if (conv == 6)
		len = o_conversion(table);
	if (conv == 7)
		len = u_conversion(table);
	if (conv == 8)
		len = x_conversion(table);
	if (conv == 9)
		len = cap_x_conversion(table);
	if (conv == 10)
		len = f_conversion(table);
	if (conv == 11)
		len = percent_conversion(table);
	return (len);
}
