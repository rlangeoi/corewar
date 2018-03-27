/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:27:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/11 00:36:30 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (!(s))
		return (NULL);
	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s[len])
	{
		str[len] = (*f)(s[len]);
		len++;
	}
	str[len] = '\0';
	return (str);
}
