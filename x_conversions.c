/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:22:50 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:08:49 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	actual_x_conversion(size_t nbr, t_table *table, char *str, char *tmp)
{
	char		*prefix;
	char		*suffix;

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
	char		*tmp;

	if (table->cursor->l == 1)
		n = va_arg(table->args, unsigned long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, unsigned long long int);
	else
		n = va_arg(table->args, unsigned int);
	str = pretreat_x(table, n);
	build_output(table, str);
	actual_x_conversion(n, table, str, tmp);
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
	char		*tmp;

	if (table->cursor->l == 1)
		n = va_arg(table->args, unsigned long int);
	else if (table->cursor->ll == 1)
		n = va_arg(table->args, unsigned long long int);
	else
		n = va_arg(table->args, unsigned int);
	str = pretreat_x(table, n);
	build_output(table, str);
	actual_x_conversion(n, table, str, tmp);
	ft_make_cap(table->cursor->argument);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}
