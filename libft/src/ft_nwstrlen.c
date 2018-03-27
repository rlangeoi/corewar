/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nwstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:42:43 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/25 15:50:09 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nwstrlen(wchar_t *s, int len)
{
	int size;
	int i;

	size = 0;
	i = 0;
	if (!s)
		return (-1);
	while (*s != '\0' && i < len)
	{
		i = i + ft_wcharlen(*s);
		if (i <= len)
			size = i;
		s++;
	}
	return (size);
}
