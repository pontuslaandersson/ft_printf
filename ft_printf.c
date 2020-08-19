/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:46:44 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:30:02 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	t_table		*table;
	int			ret;

	ret = 0;
	if (ft_strcmp(format, "%") == 0)
		return (0);
	if (!(table = (t_table*)malloc(sizeof(t_table))))
		return (-1);
	table = create_table(table);
	if (format && (ft_strcmp(format, "%") != 0))
	{
		va_start(table->args, format);
		table->len = resolve(table, format);
		va_end(table->args);
	}
	ret = table->len;
	free(table);
	return (ret);
}

int			ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_table		*table;
	char		*tmp;
	int			ret;

	ret = 0;
	if (!(table = (t_table*)malloc(sizeof(t_table))))
		return (-1);
	table = create_table(table);
	tmp = ft_strdup(format);
	if (format && (ft_strcmp(format, "%") != 0))
	{
		va_start(table->args, format);
		ret = sresolve(table, str, tmp, size);
		va_end(table->args);
	}
	free(table);
	free(tmp);
	return (ret);
}
