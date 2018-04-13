/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:14:02 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/12 16:01:55 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_lstdelcontent(void *content, size_t content_size)
{
	unsigned char	*mem;

	mem = (unsigned char*)content;
	if (mem)
	{
		mem += content_size - 1;
		while (--content_size)
		{
			free(mem);
			mem--;
		}
	}
}

void		ft_lstrm(t_list **alst, t_list *prev)
{
	t_list *next;
	void	(*f)(void*, size_t);

	f = &ft_lstdelcontent;
	if (*alst)
	{
		next = (*alst)->next;
		if (prev)
			prev->next = (*alst)->next;
		ft_lstdelone(alst, f);
		if (prev)
			(*alst) = prev;
		else
			(*alst) = next;
	}
}
