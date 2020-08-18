/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:50:05 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 21:30:42 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			free_conversions(t_table *table)
{
	t_conversion	*conv;

	table->cursor = table->conversions;
	while (table->cursor != NULL)
	{
		conv = table->cursor;
		table->cursor = table->cursor->next;
		free(conv);
	}
}

void				with_args(t_table *table, const char *format)
{
	int		i;

	i = 0;
	table->cursor = table->conversions;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			table->len = (table->len - 1) + handle_conversion(table, \
				table->cursor->conv);
			ft_putnstr(table->cursor->argument, table->cursor->len);
			free(table->cursor->argument);
			i = jump_i(format, i);
			table->cursor = table->cursor->next;
		}
		else
			write(1, &format[i], 1);
		++i;
		++table->len;
	}
	free_conversions(table);
}

void				only_format(t_table *table, const char *format)
{
	ft_putstr(format);
	table->len = ft_strlen(format);
}

int					resolve(t_table *table, const char *format)
{
	int		arg;

	arg = parse_args(table, format);
	if (arg > 0)
	{
		with_args(table, format);
	}
	else
		only_format(table, format);
	return (table->len);
}
