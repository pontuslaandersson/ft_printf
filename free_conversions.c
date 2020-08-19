/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:01:09 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 16:03:32 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_conversions(t_table *table)
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
