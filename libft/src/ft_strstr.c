/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:36:44 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/08 21:37:53 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ret;
	int			i;

	ret = s1;
	if (*s2 == '\0')
		return ((char*)ret);
	while (*s1 != '\0')
	{
		i = 0;
		ret = s1;
		while (s1[i] == s2[i] && s1[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char*)ret);
		s1++;
	}
	return (NULL);
}
