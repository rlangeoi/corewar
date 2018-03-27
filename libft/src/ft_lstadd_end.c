/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:38:23 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:38:25 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*end;

	end = *alst;
	if (*alst != NULL && new != NULL)
	{
		while (end->next)
			end = end->next;
		end->next = new;
		end = end->next;
	}
	else if (*alst == NULL && new != NULL)
	{
		*alst = new;
		return (*alst);
	}
	return (end);
}
