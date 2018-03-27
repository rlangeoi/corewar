/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:35:41 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/08 21:36:02 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ret;

	ret = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if (c == 0)
		ret = s;
	return ((char*)ret);
}
