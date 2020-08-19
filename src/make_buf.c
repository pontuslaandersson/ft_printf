/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:05:26 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:25:37 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_buf(t_table *table, char *buf, char *tmp, size_t n)
{
	int		i;

	i = 0;
	table->len = ft_strlen(tmp);
	while (i < (int)n - 1 && i < (int)table->len)
	{
		buf[i] = tmp[i];
		++i;
	}
	free(tmp);
	buf[i] = '\0';
}
