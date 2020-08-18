/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:47:51 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 20:06:23 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		jump_i(const char *str, int start)
{
	int j;

	j = start;
	while (str[j] != '\0')
	{
		++j;
		if (is_conversion(str, j) > 0)
			break ;
	}
	return (j);
}
