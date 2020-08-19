/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nul_c_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:51:39 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:52:04 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*join_value(char *s1, char *s2, int len1, int len2)
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

static char			*append_suffix_to_nul(char *s1)
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

static void	do_null_prefix(t_table *table, char *prefix, char *tmp, size_t len)
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
