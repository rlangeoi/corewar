/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 06:28:01 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/16 06:30:45 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putunbr(unsigned long long n)
{
	unsigned long long i;

	i = (unsigned long long)n;
	if (i < 10)
		ft_putchar(i + '0');
	if (i >= 10)
	{
		ft_putunbr(i / 10);
		ft_putunbr(i % 10);
	}
}
