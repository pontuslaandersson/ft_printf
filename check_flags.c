/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:13 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:34:27 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for flag characters and sets the appropriate switches in the table.
** Return: 1 on flag found; 0 on no flag.
*/

int			set_h(const char *format, int i, t_table *table)
{
	if (format[i + 1] == 'h')
		table->cursor->hh = 1;
	else
		table->cursor->h = 1;
	return (1);
}

int			set_l(const char *format, int i, t_table *table)
{
	if (format[i + 1] == 'l')
		table->cursor->ll = 1;
	else
		table->cursor->l = 1;
	return (1);
}

int			is_flag(const char *format, int i, t_table *table)
{
	if (format[i] == 'h')
		return (set_h(format, i, table));
	if (format[i] == 'l')
		return (set_l(format, i, table));
	if (format[i] == 'L')
	{
		table->cursor->cap_l = 1;
		return (1);
	}
	if (format[i] == '#')
	{
		table->cursor->hash = 1;
		return (1);
	}
	if (format[i] == '+')
	{
		table->cursor->plus = 1;
		return (1);
	}
	if (format[i] == ' ')
	{
		table->cursor->space = 1;
		return (1);
	}
	return (0);
}

void		check_flags(const char *format, t_table *table, int start)
{
	int		i;
	int		ret;

	i = start + 1;
	ret = 0;
	while (is_conversion(format, i) == 0)
	{
		ret = is_flag(format, i, table);
		if (ret > 0)
			break ;
		++i;
	}
}
