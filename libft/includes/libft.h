/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:01:34 by panderss          #+#    #+#             */
/*   Updated: 2020/08/19 17:12:37 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_fbitshift
{
	unsigned long long	m;
	unsigned short		exp;
}						t_fbitshift;

typedef union			u_fsignbit
{
	long double			ld;
	t_fbitshift			shifter;
}						t_fsignbit;

/*
** Part Un - Libc functions
*/
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst, \
							const void *src, int c, size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *src);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle, \
							size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

/*
** Part Dos - Additional functions
*/
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *str);
void					ft_striter(char *str, void (*f)(char *));
void					ft_striteri(char *str, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s, \
							char (*f)(unsigned int, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, unsigned int start, \
							size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *str);
char					**ft_strsplit(const char *s, char c);
char					*ft_itoa(int n);
char					*ft_itoa_base(unsigned long int n, \
							unsigned long int base);
char					*ft_lltoa(long long int n);
char					*ft_ltoa(long int n);
char					*ft_utoa(unsigned int n);
char					*ft_ulltoa(unsigned long long int n);
char					*ft_ulltoa_base(unsigned long long int n, \
							unsigned long int base);
char					*ft_ultoa(unsigned long int n);
char					*ft_ultoa_base(unsigned long int n, \
							unsigned long int base);
void					ft_putchar(char c);
void					ft_putstr(const char *str);
void					ft_putendl(const char *str);
void					ft_putnbr(int nb);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *str, int fd);
void					ft_putendl_fd(const char *str, int fd);
void					ft_putnbr_fd(int n, int fd);

/*
** Bonus: list-manipulating functions
*/

t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst, \
							void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Bonus useful functions
*/

int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_isspace(int c);
int						ft_isblank(int c);
int						ft_signbit(long double nb);
void					ft_reversecase(char *c);
int						ft_iswhitespace(int c);
char					*ft_strndup(const char *src, size_t n);
char					*ft_strrep(const char *s, char *match, char *rep);

#endif
