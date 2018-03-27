/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:07 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:36:10 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *alst)
{
	size_t	size;

	size = 0;
	while (alst)
	{
		size++;
		alst = alst->next;
	}
	return (size);
}
