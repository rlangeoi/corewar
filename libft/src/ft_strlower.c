/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:37:14 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 20:14:29 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	if (str)
	{
		while (*str)
		{
			*str = (char)ft_tolower((int)*str);
			str++;
		}
		return (str);
	}
	return (NULL);
}
