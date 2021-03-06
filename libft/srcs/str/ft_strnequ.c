/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:50:58 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 17:45:41 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!(s1) || !(s2))
		return (0);
	if (!*s1 || !*s2)
		return (1);
	while (n-- && *s1 && *s2 && (*s1 == *s2) && *s1++ && *s2++)
	{
		if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
			return (1);
	}
	return (0);
}
