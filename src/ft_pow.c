/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:44:17 by panderss          #+#    #+#             */
/*   Updated: 2020/08/06 15:44:19 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double				ft_pow(double n, long pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}
