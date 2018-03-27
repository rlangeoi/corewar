/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:56 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:35:59 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstend(t_list *alst)
{
	if (!alst)
		return (NULL);
	while (alst->next)
		alst = alst->next;
	return (alst);
}
