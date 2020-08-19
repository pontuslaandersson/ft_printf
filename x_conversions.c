/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:22:50 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:31:18 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	actual_x_conversion(t_table *table)
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

char	*pretreat_x(t_table *table, size_t n)
{
	char		*s;
	char		*tmp;

	if (table->cursor->ll == 1)
		tmp = ft_ulltoa_base(n, 16);
	else
		tmp = ft_ultoa_base(n, 16);
	if (table->cursor->hash == 1 && n != 0)
	{
		s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	else
	{
		s = ft_strndup(tmp, ft_strlen(tmp));
		free(tmp);
	}
	return (s);
}

size_t	x_conversion(t_table *table)
{
	ssize_t		n;
	char		*str;

	if (table->cursor->l == 1)
		n = va_arg(table->args, unsigned long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, unsigned long long int);
	else
		n = va_arg(table->args, unsigned int);
	str = pretreat_x(table, n);
	build_output(table, str);
	actual_x_conversion(table);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}

void	ft_make_cap(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		++i;
	}
}

size_t	cap_x_conversion(t_table *table)
{
	ssize_t		n;
	char		*str;

	if (table->cursor->l == 1)
		n = va_arg(table->args, unsigned long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, unsigned long long int);
	else
		n = va_arg(table->args, unsigned int);
	str = pretreat_x(table, n);
	build_output(table, str);
	actual_x_conversion(table);
	ft_make_cap(table->cursor->argument);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}
