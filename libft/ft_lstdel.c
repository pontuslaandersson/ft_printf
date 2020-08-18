/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:56:12 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 12:52:47 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nextlist;

	if (*alst)
	{
		list = *alst;
		while (list)
		{
			nextlist = list->next;
			del(list->content, list->content_size);
			free(list);
			list = nextlist;
		}
		*alst = NULL;
	}
}
