/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:02 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 22:09:44 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ftoa(double n, long precision)
{
	char	*res;
	long	ipart;
	double	fpart;
	long	i;
	long	len;

	ipart = (long)n;
	while (n >= 1.0000000)
		n--;
	fpart = n;
	len = itoa_length(ipart) + precision + 1;
	res = ft_strnew(len + 1);
	i = longtostr(ipart, res, 0);
	if (ipart == 0)
	{
		res[0] = '0';
		++i;
	}
	if (precision != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, precision);
		longtostr((long)fpart, res + i + 1, precision);
	}
	return (res);
}

/*long double	ft_modf(long double x, long double *integer)
{
	long double int_part;

	int_part = (long double)(long int)x;
	*integer = int_part;
	return (x - int_part);
}

static long double	rounding(long double nb, int precision)
{
	long double	rounding;
	long double int_val;

	ft_modf(nb, &int_val);
	rounding = precision == 0 && (int)int_val % 2 == 0 ? 0.499 : 0.500;
	if (nb == 0)
		return (nb);
	if (nb < 0)
		rounding *= -1;
	while (precision-- > 0)
		rounding /= 10.0;
	return (rounding);
}

static int			ft_signbit(long double nb)
{
	t_fsignbit			signbit;

	signbit.ld = nb;
	return (int)(signbit.shifter.exp >> 15);
}

static char			*get_floor_value(long double n)
{
	long double			int_val;
	long double			dec_val;
	char				*ret;
	char				*minus_sign;
	char				*temp;

	minus_sign = NULL;
	dec_val = ft_modf(n, &int_val);
	if (ft_signbit(n) && dec_val <= 0)
		minus_sign = ft_strdup("-");
	n *= (n < 0) ? -1 : 1;
	ret = ft_itoa_base(n, 10);
	if (minus_sign)
	{
		temp = ft_strjoin(minus_sign, ret);
		free(ret);
		ret = ft_strdup(temp);
		free(temp);
		free(minus_sign);
	}
	return (ret);
}

char				*ftoa(long double n, int precision)
{
	unsigned long long	dec;
	char				*ipart;
	char				*fpart;
	char				*ret;
	int					i;

	n = n + rounding(n, precision);
	ipart = get_floor_value(n);
	n *= (n < 0) ? -1 : 1;
	dec = n;
	n = precision ? (n - dec) : 0;
	fpart = ft_strnew(precision + 2);
	fpart[0] = '.';
	i = 0;
	while (precision > i++)
	{
		n *= 10;
		dec = n;
		n -= dec;
		fpart[i] = dec + '0';
	}
	ret = precision > 0 ? ft_strjoin(ipart, fpart) : ft_strdup(ipart);
	free(fpart);
	free(ipart);
	return (ret);
}*/