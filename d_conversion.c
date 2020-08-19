/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:53:59 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:30:38 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			actual_d_conversion(size_t nbr, t_table *table, char *str)
{
	char				*tmp;
	char				*prefix;
	char				*suffix;

	prefix = build_prefix(table, table->cursor->argument);
	if (prefix != NULL)
	{
		tmp = ft_strjoin(prefix, table->cursor->argument);
		free(table->cursor->argument);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(prefix);
	}
	suffix = build_suffix(table, table->cursor->argument);
	if (suffix != NULL)
	{
		tmp = ft_strjoin(table->cursor->argument, suffix);
		free(table->cursor->argument);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(suffix);
	}
	return (ft_strlen(table->cursor->argument));
}

void			pretreat_str(t_table *table, char *str, ssize_t n)
{
	char		*tmp;

	if (table->cursor->plus == 1 && n > 0 && table->cursor->space == 0)
	{
		tmp = ft_strjoin("+", str);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	else if (n > 0 && table->cursor->space == 1)
	{
		tmp = ft_strjoin(" ", str);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
}

char			*prepretreat_str(t_table *table, size_t n)
{
	char		*s;
	char		*tmp;

	if (table->cursor->l == 1)
		tmp = ft_ltoa(n);
	else if (table->cursor->ll == 1)
		tmp = ft_lltoa(n);
	else
		tmp = ft_itoa(n);
	s = ft_strndup(tmp, ft_strlen(tmp));
	free(tmp);
	return (s);
}

size_t			d_conversion(t_table *table)
{
	ssize_t		n;
	char		*str;
	size_t		ret;

	if (table->cursor->l == 1)
		n = va_arg(table->args, long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, long long int);
	else
		n = va_arg(table->args, int);
	str = prepretreat_str(table, n);
	build_output(table, str);
	pretreat_str(table, table->cursor->argument, n);
	ret = actual_d_conversion(n, table, str);
	table->cursor->len = ret;
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ret);
}
