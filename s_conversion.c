/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:08:09 by panderss          #+#    #+#             */
/*   Updated: 2020/08/13 19:24:18 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			actual_actual_s_conversion(t_table *table, char *str)
{
	char		*prefix;
	char		*suffix;
	char		*tmp;
	size_t		ret;

	prefix = build_prefix(table, table->cursor->argument);
	if (prefix)
	{
		tmp = ft_strjoin(prefix, table->cursor->argument);
		free(table->cursor->argument);
		free(prefix);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
	}
	suffix = build_suffix(table, table->cursor->argument);
	if (suffix)
	{
		tmp = ft_strjoin(table->cursor->argument, suffix);
		free(table->cursor->argument);
		free(suffix);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
	}
	return (ft_strlen(table->cursor->argument));
}

size_t			ws_conversion(t_table *table)
{
	char		*str;
	size_t		ret;

	str = va_arg(table->args, char *);
	build_output(table, str);
	actual_actual_s_conversion(table, str);
	table->cursor->len = ret;
	return (ret);
}

size_t			actual_s_conversion(t_table *table)
{
	char		*str;
	size_t		ret;

	str = va_arg(table->args, char *);
	if (str == NULL)
		table->cursor->argument = ft_strdup("(null)");
	else
		build_output(table, str);
	ret = actual_actual_s_conversion(table, str);
	table->cursor->len = ret;
	return (ret);
}

size_t			s_conversion(t_table *table)
{
	size_t		ret;

	ret = 0;
	if (table->cursor->l == 1)
		ret = ws_conversion(table);
	else
		ret = actual_s_conversion(table);
	return (ret);
}
