/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:01:57 by panderss          #+#    #+#             */
/*   Updated: 2020/07/10 17:31:43 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_first(const char *s, char *dest, char *match)
{
	int i;

	i = 0;
	while (s[i] != match[0])
	{
		dest[i] = s[i];
		++i;
	}
}

static void		get_second(const char *s, char *dest, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		dest[j] = s[i];
		++i;
		++j;
	}
}

char			*ft_strrep(const char *s, char *match, char *rep)
{
	char	*tmp1;
	char	*tmp2;
	char	*ret;
	int		i;

	i = 0;
	while (s[i] != match[0])
		++i;
	tmp1 = ft_strnew(i);
	get_first(s, tmp1, match);
	ret = ft_strjoin(tmp1, rep);
	free(tmp1);
	tmp1 = ft_strnew(ft_strlen(s) - i - ft_strlen(match));
	i = i + (ft_strlen(match));
	get_second(s, tmp1, i);
	tmp2 = ft_strjoin(ret, tmp1);
	free(ret);
	ret = tmp2;
	return (ret);
}
