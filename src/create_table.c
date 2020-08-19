/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:30 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:55:57 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_table		*create_table(t_table *table)
{
	table->conversions = NULL;
	table->output = NULL;
	table->len = 0;
	table->i = 0;
	return (table);
}
