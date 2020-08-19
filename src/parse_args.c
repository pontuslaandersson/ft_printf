/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:48:22 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:34:13 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		first_conversion(t_table *table)
{
	table->cursor->next = (t_conversion*)malloc(sizeof(t_conversion));
	table->cursor = table->cursor->next;
	table->cursor->conv = 0;
	table->cursor->zero_pad = 0;
	table->cursor->width = 0;
	table->cursor->precision = 6;
	table->cursor->f_sign = 1;
	table->cursor->hash = 0;
	table->cursor->h = 0;
	table->cursor->hh = 0;
	table->cursor->cap_l = 0;
	table->cursor->l = 0;
	table->cursor->ll = 0;
	table->cursor->plus = 0;
	table->cursor->space = 0;
	table->cursor->len = 0;
	table->cursor->next = NULL;
}

void		new_conversion(t_table *table)
{
	table->conversions = (t_conversion*)malloc(sizeof(t_conversion));
	table->conversions->conv = 0;
	table->conversions->zero_pad = 0;
	table->conversions->width = 0;
	table->conversions->precision = 6;
	table->conversions->f_sign = 1;
	table->conversions->hash = 0;
	table->conversions->h = 0;
	table->conversions->hh = 0;
	table->conversions->cap_l = 0;
	table->conversions->l = 0;
	table->conversions->ll = 0;
	table->conversions->plus = 0;
	table->conversions->space = 0;
	table->conversions->len = 0;
	table->conversions->next = NULL;
	table->cursor = table->conversions;
}

void		add_conversion(t_table *table)
{
	if (table->conversions != NULL)
	{
		first_conversion(table);
	}
	else
	{
		new_conversion(table);
	}
}

int			parse_args(t_table *table, const char *format)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			add_conversion(table);
			table->cursor->precision = get_precision(table, format, i);
			table->cursor->width = get_width(table, format, i);
			check_flags(format, table, i);
			table->cursor->conv = check_conversion(format, i);
			i = jump_i(format, i);
			++ret;
		}
		++i;
	}
	return (ret);
}
