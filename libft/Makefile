# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panderss <panderss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 17:17:19 by panderss          #+#    #+#              #
#    Updated: 2020/08/19 13:34:41 by panderss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_memset.c \
      ./ft_bzero.c \
      ./ft_memcpy.c \
      ./ft_memccpy.c \
      ./ft_memmove.c \
      ./ft_memchr.c \
      ./ft_memcmp.c \
      ./ft_strlen.c \
      ./ft_strdup.c \
      ./ft_strcpy.c \
      ./ft_strncpy.c \
      ./ft_strcat.c \
      ./ft_strncat.c \
      ./ft_strlcat.c \
      ./ft_strchr.c \
      ./ft_strrchr.c \
      ./ft_strstr.c \
      ./ft_strnstr.c \
      ./ft_strcmp.c \
      ./ft_strncmp.c \
      ./ft_atoi.c \
      ./ft_isalpha.c \
      ./ft_isdigit.c \
      ./ft_isalnum.c \
      ./ft_isascii.c \
      ./ft_isprint.c \
      ./ft_toupper.c \
      ./ft_tolower.c \
      ./ft_memalloc.c \
      ./ft_memdel.c \
      ./ft_strnew.c \
      ./ft_strdel.c \
      ./ft_strclr.c \
      ./ft_striter.c \
      ./ft_striteri.c \
      ./ft_strmap.c \
	./ft_strmapi.c \
      ./ft_strequ.c \
      ./ft_strnequ.c \
	./ft_strsub.c \
      ./ft_strrep.c \
	./ft_strjoin.c \
	./ft_strtrim.c \
	./ft_strsplit.c \
      ./ft_itoa.c \
      ./ft_itoa_base.c \
	  ./ft_lltoa.c \
	./ft_ltoa.c \
	  ./ft_utoa.c \
	  ./ft_ulltoa.c \
	  ./ft_ulltoa_base.c \
	  ./ft_ultoa.c \
	  ./ft_ultoa_base.c \
      ./ft_putchar.c \
      ./ft_putstr.c \
      ./ft_putendl.c \
      ./ft_putnbr.c \
      ./ft_putchar_fd.c \
      ./ft_putstr_fd.c \
      ./ft_putendl_fd.c \
      ./ft_putnbr_fd.c \
	./ft_islower.c \
	./ft_isupper.c \
	./ft_isspace.c \
	./ft_reversecase.c \
	./ft_lstnew.c \
	./ft_lstdelone.c \
	./ft_lstdel.c \
	./ft_lstadd.c \
	./ft_lstiter.c \
	./ft_lstmap.c \
	./ft_isblank.c \
	./ft_iswhitespace.c \
      ./ft_strndup.c \
	  ./ft_signbit.c

INCLUDES = ./includes/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I ./includes/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
