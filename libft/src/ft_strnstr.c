/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:33:01 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/24 17:55:42 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*ret;
	int			i;
	int			j;

	ret = s1;
	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	j = 0;
	while (j < (int)n && s1[j] != '\0')
	{
		while ((j + i) < (int)n && (s1[i + j] == s2[i]) &&
				s1[i + j] != '\0' && s2[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char*)(ret + j));
		j++;
		i = 0;
	}
	return (NULL);
}
