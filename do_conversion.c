/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:42 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 21:15:00 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*join_value(char *s1, char *s2, int len1, int len2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_memalloc(len1 + len2);
	while (i < len1)
	{
		ret[i] = s1[i];
		++i;
	}
	while (j < len2)
	{
		ret[i + j] = s2[j];
		++j;
	}
	return (ret);
}

char			*append_suffix_to_nul(char *s1)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + 1;
	ret = ft_memalloc(len);
	ret[0] = '\0';
	++i;
	while (i + j < len)
	{
		ret[i + j] = s1[j];
		++j;
	}
	return (ret);
}

void	do_null_prefix(t_table *table, char *prefix, char *tmp, size_t len)
{
	tmp = join_value(prefix, table->cursor->argument, (ft_strlen(prefix)), 1);
	len = len + ft_strlen(prefix);
	free(table->cursor->argument);
	table->cursor->argument = ft_strndup(tmp, (ft_strlen(prefix) + 1));
	free(tmp);
	free(prefix);
}

size_t			nul_c_conversion(t_table *table)
{
	char		*prefix;
	char		*suffix;
	char		*tmp;
	size_t		len;

	len = 0;
	prefix = build_prefix(table, "*");
	if (prefix)
	{
		do_null_prefix(table, prefix, tmp, len);
	}
	suffix = build_suffix(table, "*");
	if (suffix)
	{
		free(table->cursor->argument);
		table->cursor->argument = append_suffix_to_nul(suffix);
		len = len + ft_strlen(suffix);
		free(suffix);
	}
	return (len + 1);
}

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
