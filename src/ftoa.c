/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:02 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 13:07:57 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** Gets a string representing a floating point number n, limited by precision,
** and rounded with bankers' rounding.
** Completes this without being unduly slow.
*/

char				*build_float(char *i_str, char *dec)
{
	char	*ret;
	char	*tmp;

	ret = ft_strnew(ft_strlen(i_str) + ft_strlen(dec) + 1);
	tmp = ft_strjoin(i_str, ".");
	ret = ft_strjoin(tmp, dec);
	free(tmp);
	return (ret);
}

char				*ftoa(double n, long precision)
{
	char	*ret;
	int		len;
	int		i;
	long	ipart;
	long double		integer;
	long double		fpart;
	char	*i_str;
	char	*dec;
	char	*tmp;

	ipart = (long)n;
	//printf("n = %f\n.", n);
	//ft_putendl("Debug.");
	fpart = ft_modf((long double)n, &integer);
	//printf("precision = %ld\n", precision);
	//len = itoa_length(ipart) + precision;
	//ret = ft_strnew(len + 1);
	len = itoa_length(ipart);
	//ft_putnbr(len);
	//ft_putendl("");
	i_str = ft_strnew(len);
	if (n == 0)
	{
		i_str[0] = '0';
		++i;
	}
	i_str = longtostr(ipart, 0, len);
	//ft_putnbr(precision);
	//ft_putendl("<= precision");
	if (precision != 0)
	{
		//printf("Adding decimal point at %d\n.", i);
		//ret[i] = '.';
		//i = precision;
		fpart = fpart * ft_pow(10, precision);
		//printf("fpart = %Lf\n.", fpart);
		//ft_putnbr(precision);
		//ft_putendl("<= mallocing for dec string.");
		//dec = ft_strnew(precision);
		dec = longtostr((long)fpart, precision, precision);
	}
	//ret = ft_strdup("output of f conversion");
	//tmp = ft_strjoin(ret, dec);
	//free(ret);
	//ret = ft_strdup(tmp);
	//free(tmp);
	//printf("i_str: %s\n", i_str);
	if (precision != 0)
		ret = build_float(i_str, dec);
	else
		ret = ft_strdup(i_str);
	//ft_putendl(ret);
	//ft_putendl("Preparing to free i string.");
	free(i_str);
	//ft_putendl("Successfully freed i string.");
	if (precision != 0)
	{
		//ft_putendl("Preparing to free decimal string.");
		free(dec);
		//ft_putendl("Successfully freed decimal string.");
	}
	return (ret);
}

/*char				*ftoa(double n, long precision)
{
	char	*res;
	char	*dec;
	long	ipart;
	double	fpart;
	long	i;
	long	len;

	ipart = (long)n;
	while (n >= 1.0000000)
		n--;
	fpart = n;
	len = itoa_length(ipart) + precision + 1;
	res = ft_strnew(len);
	i = longtostr(ipart, res, 0, (len - precision - 2));
	i = len - precision - 1;
	//ft_putnbr(len);
	//ft_putendl(" <= len in ftoa.");
	//ft_putnbr(i);
	//ft_putendl(" <= i in ftoa, for decimal point.");
	if (ipart == 0)
	{
		res[0] = '0';
		++i;
	}
	if (precision != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, precision);
		dec = ft_strnew(precision);
		longtostr((long)fpart, dec, precision - 1, precision);
	}
	ft_putstr("res: ");
	ft_putendl(res);
	return (res);
}*/
