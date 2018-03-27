/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:27:07 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/24 20:33:41 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		if (*str < 0x80)
			len++;
		else if (*str < 0x800)
			len += 2;
		else if (*str < 0x10000)
			len += 3;
		else if (*str < 0x110000)
			len += 4;
		str++;
	}
	return (len);
}
