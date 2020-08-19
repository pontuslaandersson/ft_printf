/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:47:17 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:40:31 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		handle_conversion(t_table *table, int conv)
{
	size_t	len;

	len = do_conversion(table, conv);
	return (len);
}
