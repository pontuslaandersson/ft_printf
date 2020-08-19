/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:43:53 by panderss          #+#    #+#             */
/*   Updated: 2020/08/11 17:47:15 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_s(t_table *table, char *str)
{
	if (str == NULL)
		table->cursor->argument = ft_strdup("(null)");
	if (table->cursor->precision != -1)
		table->cursor->argument = ft_strndup(str, table->cursor->precision);
	else
		table->cursor->argument = ft_strdup(str);
}

void	expand(t_table *table, int padding, char *str)
{
	int		i;
	char	*pad;
	char	*tmp;

	i = 0;
	pad = ft_strnew(padding);
	while (i < padding)
	{
		pad[i] = '0';
		++i;
	}
	tmp = ft_strjoin(pad, str);
	free(pad);
	table->cursor->argument = ft_strdup(tmp);
	free(tmp);
}

void	output_d(t_table *table, char *s)
{
	if (s == NULL)
		table->cursor->argument = ft_strdup("(null)");
	if (table->cursor->precision != -1 &&
			table->cursor->precision < (long)ft_strlen(s))
		table->cursor->argument = ft_strndup(s, table->cursor->precision);
	else if (table->cursor->precision != -1 &&
			table->cursor->precision > (long)ft_strlen(s))
		expand(table, (int)(table->cursor->precision - (long)ft_strlen(s)), s);
	else
		table->cursor->argument = ft_strdup(s);
}

void	output_f(t_table *table, char *str)
{
	if (str == NULL)
		table->cursor->argument = ft_strdup("(null)");
	else
		table->cursor->argument = ft_strdup(str);
}

void	build_output(t_table *table, char *str)
{
	if (table->cursor->conv == 1)
		output_s(table, str);
	if (table->cursor->conv == 3)
		output_d(table, str);
	if (table->cursor->conv == 4 || table->cursor->conv == 5)
		output_d(table, str);
	if (table->cursor->conv == 6)
		output_d(table, str);
	if (table->cursor->conv == 7)
		output_d(table, str);
	if (table->cursor->conv == 8)
		output_d(table, str);
	if (table->cursor->conv == 9)
		output_d(table, str);
	if (table->cursor->conv == 10)
		output_f(table, str);
}
