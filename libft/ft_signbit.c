/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signbit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:32:52 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:38:02 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_signbit(long double nb)
{
	t_fsignbit			signbit;

	signbit.ld = nb;
	return (int)(signbit.shifter.exp >> 15);
}
