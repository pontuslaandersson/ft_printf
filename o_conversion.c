/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:44:54 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:55:13 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			actual_o_conversion(size_t nbr, t_table *table, char *str)
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
}

char			*pretreat_o(t_table *table, ssize_t n)
{
	char		*s;
	char		*tmp;

	if (table->cursor->ll == 1)
		tmp = ft_itoa_base(n, 8);
	else if (table->cursor->ll == 1)
		tmp = ft_ulltoa_base(n, 8);
	else
		tmp = ft_itoa_base(n, 8);
	s = ft_strndup(tmp, ft_strlen(tmp));
	free(tmp);
	return (s);
}

size_t			o_conversion(t_table *table)
{
	ssize_t		n;
	char		*str;
	char		*tmp;

	if (table->cursor->l == 1)
		n = va_arg(table->args, unsigned long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, unsigned long long int);
	else
		n = va_arg(table->args, unsigned int);
	str = pretreat_o(table, n);
	if (table->cursor->hash == 1)
	{
		tmp = ft_strjoin("0", str);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	build_output(table, str);
	actual_o_conversion(n, table, str);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}
