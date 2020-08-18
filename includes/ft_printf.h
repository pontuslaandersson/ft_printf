/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:50:53 by panderss          #+#    #+#             */
/*   Updated: 2020/08/18 22:10:17 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <limits.h>

typedef struct			s_conversion
{
	char				*conv_str;
	char				*argument;
	int					conv;
	long				width;
	long				precision;
	int					f_sign;
	int					hash;
	int					h;
	int					hh;
	int					cap_l;
	int					l;
	int					ll;
	int					space;
	int					plus;
	int					zero_pad;
	int					len;
	struct s_conversion	*next;
}						t_conversion;

typedef struct			s_table
{
	char				*format;
	char				*output;
	t_conversion		*conversions;
	t_conversion		*cursor;
	va_list				args;
	size_t				len;
	size_t				i;
}						t_table;

typedef struct s_fbitshift
{
	unsigned long long 	m;
	unsigned short		exp;
}						t_fbitshift;


typedef union	u_fsignbit
{
	long double			ld;
	t_fbitshift			shifter;
}						t_fsignbit;

void					build_output(t_table *table, char *str);
char					*build_prefix(t_table *table, char *str);
char					*build_suffix(t_table *table, char *str);
int						check_conversion(const char *format, int start);
t_table					*create_table(t_table *table);
void					check_flags(const char *format, t_table *table, \
							int start);
size_t					display_width(long int width);
size_t					display_zeros(t_table *table, int n);
size_t					do_conversion(t_table *table, int conv);
size_t					f_conversion(t_table *table);
long int				ft_atol(const char *str, long int start);
char					*ft_itoa_base_cap(int n, int base);
double					ft_prep_float(long double n, t_table *table);
int						ft_printf(const char *format, ...);
void					ft_putnstr(const char *str, int len);
long int				get_precision(t_table *table, const char *format, int i);
long int				get_width(t_table *table, const char *format, int i);
size_t					handle_conversion(t_table *table, int conv);
int						is_conversion(const char *format, int i);
size_t					jump_i(const char *str, int start);
int						resolve(t_table *table, const char *format);
int						parse_args(t_table *table, const char *format);
void					ft_strrev(char *str, long len);
double					ft_pow(double n, long pow);
//char					*ftoa(double n, long precision);
char					*ftoa(long double n, int precision);
char					*ldtoa(long double n, long precision);
int						itoa_length(int n);
int						sresolve(t_table *table, const char *format, char *str, size_t n);
int						ft_snprintf(char *str, size_t n, const char *format, ...);
long					longtostr(long nb, char *str, long decimals);
size_t					d_conversion(t_table *table);
size_t					o_conversion(t_table *table);
size_t					p_conversion(t_table *table);
size_t					s_conversion(t_table *table);
size_t					u_conversion(t_table *table);
size_t					cap_x_conversion(t_table *table);
size_t					x_conversion(t_table *table);

#endif
