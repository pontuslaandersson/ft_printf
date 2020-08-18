/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:47:33 by panderss          #+#    #+#             */
/*   Updated: 2020/08/05 14:42:28 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_conversion(const char *format, int i)
{
	if (format[i] == 's')
		return (1);
	if (format[i] == 'c')
		return (2);
	if (format[i] == 'p')
		return (3);
	if (format[i] == 'd')
		return (4);
	if (format[i] == 'i')
		return (5);
	if (format[i] == 'o')
		return (6);
	if (format[i] == 'u')
		return (7);
	if (format[i] == 'x')
		return (8);
	if (format[i] == 'X')
		return (9);
	if (format[i] == 'f')
		return (10);
	if (format[i] == '%')
		return (11);
	else
		return (0);
}
