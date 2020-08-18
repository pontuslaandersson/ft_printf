/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:44:54 by panderss          #+#    #+#             */
/*   Updated: 2020/08/05 13:44:56 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conversion(const char *format, int start)
{
	int		i;
	int		ret;

	i = start + 1;
	while (format[i] != '\0')
	{
		ret = is_conversion(format, i);
		if (ret > 0)
			break ;
		++i;
	}
	return (ret);
}
