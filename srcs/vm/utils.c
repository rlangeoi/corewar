/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/12 13:05:38 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			ft_lstrmone(t_list **alst, t_list *prev, void *content,
		size_t content_size)
{
	if (*alst)
	{
		if (prev)
			prev->next = (*alst)->next;
		ft_lstdelone(alst, ft_list_delcontent(content, content_size));
	}
}

void			ft_list_delcontent(void *content, size_t content_size)
{
	size_t			i;
	unsigned char	*mem;

	i = content_size;
	if (content)
	{
		mem = (unsigned char*)content;
		while (--i && mem)
			free(&mem[i]);
		if (i == 0)
			free(&mem[i]);
	}
}

unsigned int	switch_endianness(unsigned int bytes)
{
	return ((bytes >> 24) + (((bytes << 8) >> 24) << 8) +
			(((bytes << 16) >> 24) << 16) + (bytes << 24));
}
