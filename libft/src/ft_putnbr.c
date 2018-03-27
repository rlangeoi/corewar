/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:10:40 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/16 06:31:51 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_putlongmin(void)
{
	ft_putstr("-9223372036854775808");
	return ;
}

void		ft_putnbr(long long int n)
{
	long long int i;

	i = (long long int)n;
	if (i == LONG_MIN)
	{
		ft_putlongmin();
		return ;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = i * -1;
	}
	if (i < 10)
		ft_putchar(i + '0');
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
