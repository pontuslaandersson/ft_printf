/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sresolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:55:04 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:55:06 by panderss         ###   ########.fr       */
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

int             sresolve(t_table *table, const char *format, char *str, size_t n)
{
	int		arg;
	int		i;
	int		j;

	j = 0;
	i = 0;
    if (ft_strcmp(format, "%") == 0)
        return (0);
	arg = parse_args(table, format);
	if (arg > 0)
	{
		str = ft_strnew(n);
		table->cursor = table->conversions;
    	while (format[i] != '\0' && table->len < n)
    	{
        	if (format[i] == '%')
        	{
        	    table->len = (table->len - 1) + handle_conversion(table, table->cursor->conv);
				free(table->cursor->argument);
				i = jump_i(format, i);
				table->cursor = table->cursor->next;
        	}
        	else
        	    str[j] = format[i];
			++i;
			++j;
        	++table->len;
    	}
		free_conversions(table);
	}
	else
	{
		str = ft_strndup(format, n);
		table->len = ft_strlen(format);
	}
    return (table->len);
}
