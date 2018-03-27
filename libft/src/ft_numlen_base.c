/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:03:41 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/16 08:13:01 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_numlen_base(unsigned long long n, unsigned int base)
{
	size_t len;

	if (base < 2 || base > 36)
		return (0);
	len = 1;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}
