/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:59:37 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:16:43 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			actual_u_conversion(t_table *table)
{
	char				*tmp;
	char				*prefix;
	char				*suffix;

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
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(suffix);
	}
}

size_t			u_conversion(t_table *table)
{
	ssize_t		n;
	char		*str;

	if (table->cursor->l == 1)
	{
		n = va_arg(table->args, unsigned long int);
		str = ft_ultoa(n);
	}
	else if (table->cursor->ll == 1)
	{
		n = va_arg(table->args, unsigned long long int);
		str = ft_ulltoa(n);
	}
	else
	{
		n = va_arg(table->args, unsigned int);
		str = ft_utoa(n);
	}
	build_output(table, str);
	actual_u_conversion(table);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}
