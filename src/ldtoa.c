/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldtoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:54:35 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 19:53:12 by panderss         ###   ########.fr       */
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

long				dectostr(long nb, char *str, long decimals, int len)
{
	//long i;

	//i = len;
	//ft_putnbr(len);
	//ft_putendl(" <= len sent to longtostr.");
	//printf("nb = %ld\n", nb);
	while (nb && len >= 0)
	{
		//ft_putendl("Doing longtostr loop.");
		str[len--] = (nb % 10) + '0';
		//ft_putnbr(len);
		//ft_putendl(" <= inserting at this position");
		//ft_putchar((nb % 10) + '0');
		//ft_putendl("<= character for digit.");
		nb = nb / 10;
	}
	//while (i < decimals)
		//str[i++] = '0';
	//str[i] = '\0';
	//ft_strrev(str, i);
	//ft_putstr("str: ");
	//ft_putendl(str);
	return (len);
}

char				*ldtoa(long double n, long precision)
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
	if (precision != 0)
	{
		//printf("Adding decimal point at %d\n.", i);
		//ret[i] = '.';
		//i = precision;
		fpart = fpart * ft_pow(10, precision);
		//printf("fpart = %Lf\n.", fpart);
		//dec = ft_strnew(precision);
		dec = longtostr((long)fpart, precision, precision);
	}
	//ret = ft_strdup("output of f conversion");
	//tmp = ft_strjoin(ret, dec);
	//free(ret);
	//ret = ft_strdup(tmp);-6841.900��|
	//free(tmp);
	//printf("i_str: %s\n", i_str);
	ret = build_float(i_str, dec);
	//ft_putendl(ret);
	free(i_str);
	//ft_putnbr(precision);
	//ft_putendl("<= precision");
	if (precision != 0)
	{
		free(dec);
	}
	return (ret);
}


/*char				*ldtoa(long double n, long precision)
{
	char		*res;
	long		ipart;
	long double	fpart;
	long		i;
	long		len;

	ipart = (long)n;
	while (n >= 1.0000000)
		n--;
	fpart = n;
	len = itoa_length(ipart) + precision + 1;
	res = ft_strnew(len + 1);
	i = longtostr(ipart, res, 0, (len - precision - 2));
	if (ipart == 0)
	{
		res[0] = '0';
		++i;
	}
	if (precision != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, precision);
		longtostr((long)fpart, res + i + 1, precision, (len - 1));
	}
	return (res);
}*/
