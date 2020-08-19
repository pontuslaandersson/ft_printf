/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:48:04 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 17:02:23 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*expand_pointer(int padding, char *str)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = ft_strnew(padding);
	while (i < padding)
	{
		ret[i] = '0';
		++i;
	}
	tmp = ft_strjoin(ret, str);
	free(ret);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

void			do_pointer_prefix(t_table *table, char *prefix)
{
	char	*tmp;

	tmp = ft_strjoin(prefix, table->cursor->argument);
	free(table->cursor->argument);
	table->cursor->argument = ft_strdup(tmp);
	free(prefix);
	free(tmp);
}

void			actual_p_conversion(t_table *table, char *str)
{
	char				*tmp;
	char				*prefix;
	char				*suffix;

	prefix = NULL;
	table->cursor->argument = ft_strjoin("0x", str);
	if (table->cursor->zero_pad == 0 && table->cursor->width - \
			ft_strlen(table->cursor->argument) > 0)
		prefix = build_prefix(table, table->cursor->argument);
	if (prefix && table->cursor->zero_pad == 0)
	{
		do_pointer_prefix(table, prefix);
	}
	suffix = build_suffix(table, str);
	if (suffix)
	{
		tmp = ft_strjoin(table->cursor->argument, suffix);
		free(table->cursor->argument);
		table->cursor->argument = ft_strdup(tmp);
		free(tmp);
		free(suffix);
	}
}

size_t			p_conversion(t_table *table)
{
	unsigned long int	nbr;
	char				*str;

	nbr = va_arg(table->args, unsigned long int);
	str = ft_itoa_base(nbr, 16);
	if (table->cursor->zero_pad == 1 && table->cursor->width - \
			ft_strlen(str) > 0)
		str = expand_pointer((table->cursor->width - ft_strlen(str) - 2), str);
	actual_p_conversion(table, str);
	free(str);
	table->cursor->len = ft_strlen(table->cursor->argument);
	return (ft_strlen(table->cursor->argument));
}
