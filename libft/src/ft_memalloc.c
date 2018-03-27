/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:02:50 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/08 21:03:09 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ret;
	unsigned char *ptr;

	if (!(ptr = (unsigned char*)malloc(sizeof(char) * size)))
		return (NULL);
	ret = ptr;
	while (size)
	{
		*ptr = 0;
		ptr++;
		size--;
	}
	return ((void*)ret);
}
