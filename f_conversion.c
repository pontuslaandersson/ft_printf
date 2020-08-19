/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:59 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:38:34 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				do_f_argument(t_table *table, char *str)
{
	char	*prefix;
	char	*suffix;
	char	*tmp;

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
}

void				handle_sign(t_table *table, char *str, size_t n, int sb)
{
	if (table->cursor->f_sign == -1 || sb == 1)
	{
		free(table->cursor->argument);
		table->cursor->argument = ft_strjoin("-", str);
	}
	if (table->cursor->plus == 1 && n > 0 && table->cursor->space == 0)
	{
		free(table->cursor->argument);
		table->cursor->argument = ft_strjoin("+", str);
	}
	else if (n > 0 && table->cursor->space == 1)
	{
		free(table->cursor->argument);
		table->cursor->argument = ft_strjoin(" ", str);
	}
}

size_t				f_double(t_table *table)
{
	double	n;
	char	*str;
	int		sb;

	n = va_arg(table->args, double);
	sb = ft_signbit((long double)(n));
	n = ft_prep_float(n, table);
	str = ftoa(n, table->cursor->precision);
	build_output(table, str);
	handle_sign(table, str, n, sb);
	do_f_argument(table, str);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}

size_t				f_long_double(t_table *table)
{
	long double	n;
	char		*str;
	int			sb;

	n = va_arg(table->args, long double);
	sb = ft_signbit((long double)(n));
	n = ft_prep_float(n, table);
	str = ldtoa(n, table->cursor->precision);
	build_output(table, str);
	handle_sign(table, str, n, sb);
	do_f_argument(table, str);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}

size_t				f_conversion(t_table *table)
{
	size_t		ret;

	ret = 0;
	if (table->cursor->precision == -1)
		table->cursor->precision = 6;
	if (table->cursor->cap_l == 1)
		ret = f_long_double(table);
	else
		ret = f_double(table);
	return (ret);
}
