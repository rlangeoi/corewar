/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:23:11 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/11 02:26:57 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = *alst;
	while (temp)
	{
		*alst = temp;
		temp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	*alst = NULL;
}
