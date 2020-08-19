# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 13:50:32 by panderss          #+#    #+#              #
#    Updated: 2020/08/19 13:52:56 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIBFT = ./libft/ft_memset.c \
		./libft/ft_bzero.c \
		./libft/ft_memcpy.c \
		./libft/ft_memccpy.c \
		./libft/ft_memmove.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_strlen.c \
		./libft/ft_strdup.c \
		./libft/ft_strcpy.c \
		./libft/ft_strncpy.c \
		./libft/ft_strcat.c \
		./libft/ft_strncat.c \
		./libft/ft_strlcat.c \
		./libft/ft_strchr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strstr.c \
		./libft/ft_strnstr.c \
		./libft/ft_strcmp.c \
		./libft/ft_strncmp.c \
		./libft/ft_atoi.c \
		./libft/ft_isalpha.c \
		./libft/ft_isdigit.c \
		./libft/ft_isalnum.c \
		./libft/ft_isascii.c \
		./libft/ft_isprint.c \
		./libft/ft_toupper.c \
		./libft/ft_tolower.c \
		./libft/ft_memalloc.c \
		./libft/ft_memdel.c \
		./libft/ft_strnew.c \
		./libft/ft_strdel.c \
		./libft/ft_strclr.c \
		./libft/ft_striter.c \
		./libft/ft_striteri.c \
		./libft/ft_strmap.c \
		./libft/ft_strmapi.c \
		./libft/ft_strequ.c \
		./libft/ft_strnequ.c \
		./libft/ft_strsub.c \
		./libft/ft_strrep.c \
		./libft/ft_strjoin.c \
		./libft/ft_strtrim.c \
		./libft/ft_strsplit.c \
		./libft/ft_itoa.c \
		./libft/ft_itoa_base.c \
		./libft/ft_lltoa.c \
		./libft/ft_ltoa.c \
		./libft/ft_utoa.c \
		./libft/ft_ulltoa.c \
		./libft/ft_ulltoa_base.c \
		./libft/ft_ultoa.c \
		./libft/ft_ultoa_base.c \
		./libft/ft_putchar.c \
		./libft/ft_putstr.c \
		./libft/ft_putendl.c \
		./libft/ft_putnbr.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr_fd.c \
		./libft/ft_islower.c \
		./libft/ft_isupper.c \
		./libft/ft_isspace.c \
		./libft/ft_reversecase.c \
		./libft/ft_lstnew.c \
		./libft/ft_lstdelone.c \
		./libft/ft_lstdel.c \
		./libft/ft_lstadd.c \
		./libft/ft_lstiter.c \
		./libft/ft_lstmap.c \
		./libft/ft_isblank.c \
		./libft/ft_iswhitespace.c \
		./libft/ft_strndup.c \
		./libft/ft_signbit.c

SRC_PRINTF = ft_printf.c \
		build_output.c \
		build_prefix.c \
		build_suffix.c \
		check_conversion.c \
		check_flags.c \
		create_table.c \
		do_conversion.c \
		ft_atol.c \
		ft_prep_float.c \
		get_precision.c \
		handle_conversion.c \
		is_conversion.c \
		parse_args.c \
		resolve.c \
		jump_i.c \
		get_width.c \
		ft_pow.c \
		ft_putnstr.c \
		itoa_length.c \
		ft_strrev.c \
		longtostr.c \
		ftoa.c \
		ldtoa.c \
		x_conversions.c \
		p_conversion.c \
		f_conversion.c \
		u_conversion.c \
		o_conversion.c \
		d_conversion.c \
		s_conversion.c \
		sresolve.c \
		nul_c_conversion.c

INCLUDES = ./includes/

OBJ_LIBFT = ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_strlen.o \
		ft_strdup.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_atoi.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_putnstr.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strrep.o \
		ft_strjoin.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_lltoa.o \
		ft_ltoa.o \
		ft_utoa.o \
		ft_ulltoa.o \
		ft_ulltoa_base.o \
		ft_ultoa.o \
		ft_ultoa_base.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putendl.o \
		ft_putnbr.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_islower.o \
		ft_isupper.o \
		ft_isspace.o \
		ft_reversecase.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_isblank.o \
		ft_iswhitespace.o \
		ft_strndup.o \
		ft_signbit.o

OBJ_PRINTF = ft_printf.o \
		build_output.o \
		build_prefix.o \
		build_suffix.o \
		check_conversion.o \
		check_flags.o \
		create_table.o \
		do_conversion.o \
		ft_atol.o \
		ft_prep_float.o \
		get_precision.o \
		handle_conversion.o \
		is_conversion.o \
		parse_args.o \
		resolve.o \
		jump_i.o \
		get_width.o \
		ft_pow.o \
		itoa_length.o \
		ft_strrev.o \
		longtostr.o \
		ftoa.o \
		ldtoa.o \
		x_conversions.o \
		p_conversion.o \
		f_conversion.o \
		u_conversion.o \
		o_conversion.o \
		d_conversion.o \
		s_conversion.o \
		sresolve.o \
		nul_c_conversion.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC_LIBFT) -I includes/
	gcc -c $(SRC_PRINTF) -I includes/
	ar rc $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ_LIBFT)
	/bin/rm -f $(OBJ_PRINTF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
