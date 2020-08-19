/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sresolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:55:04 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 18:05:36 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_value(char *s1, char *s2, int len1, int len2)
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

static int	do_handle(t_table *table)
{
	int ret;

	ret = (table->len - 1) + handle_conversion(table, table->cursor->conv);
	return (ret);
}

void		sresolve_args(t_table *table, char *buf, const char *s, size_t n)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	table->cursor = table->conversions;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			table->len = do_handle(table);
			tmp = join_value(tmp, table->cursor->argument, i, \
				table->cursor->len);
			table->len = i - 1 + table->cursor->len;
			free(table->cursor->argument);
			i = jump_i(s, i);
			table->cursor = table->cursor->next;
		}
		else
			tmp[j] = s[i];
		++i;
		++j;
	}
	make_buf(table, buf, tmp, n);
}

void		sresolve_no_args(t_table *table, char *buf, const char *s, size_t n)
{
	int		i;
	char	*tmp;
	int		tmp_len;

	i = 0;
	tmp = ft_strdup(s);
	table->len = ft_strlen(tmp);
	tmp_len = table->len;
	while (i < (int)(n - 1) && i < tmp_len)
	{
		buf[i] = tmp[i];
		++i;
	}
	free(tmp);
	buf[i] = '\0';
}

int			sresolve(t_table *table, char *buf, const char *s, size_t n)
{
	int		arg;

	if (ft_strcmp(s, "%") == 0)
		return (0);
	arg = parse_args(table, s);
	if (arg > 0)
	{
		sresolve_args(table, buf, s, n);
		free_conversions(table);
	}
	else
		sresolve_no_args(table, buf, s, n);
	return (table->len);
}
