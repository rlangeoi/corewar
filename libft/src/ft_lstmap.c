/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:46:33 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:32:14 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !(*f))
		return (NULL);
	tmp = (*f)(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		ft_lstadd_end(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
