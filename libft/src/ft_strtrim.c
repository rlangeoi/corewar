/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:38:45 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/08 21:38:50 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	char		*new;

	if (!(s))
		return (NULL);
	i = 0;
	while ((*s == ' ') || (*s == '\t') || (*s == '\n'))
	{
		s++;
		if (!(*s))
		{
			new = ft_strnew(0);
			return (new);
		}
	}
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	new = ft_strsub(s, 0, (i + 1));
	return (new);
}
