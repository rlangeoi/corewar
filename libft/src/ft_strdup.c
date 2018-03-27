/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:18:13 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/11/01 21:19:44 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlaine(const char *s)
{
	size_t	len;

	len = 0;
	if (*s == '\0')
		return (0);
	else
	{
		len++;
		s++;
		len = len + ft_strlaine(s);
	}
	return (len);
}

char			*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		i;

	i = 0;
	len = ft_strlaine(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		exit(EXIT_FAILURE);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
