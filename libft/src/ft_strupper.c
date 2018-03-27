/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:37:20 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 20:14:46 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str)
{
	if (str)
	{
		while (*str)
		{
			*str = (char)ft_toupper((int)*str);
			str++;
		}
		return (str);
	}
	return (NULL);
}
