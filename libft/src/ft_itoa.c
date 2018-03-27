/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 00:32:00 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/11 00:32:09 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int n, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	size_t	len;
	char	*ret;

	len = ft_numlen(n);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	if (ft_min(n, ret) == 1)
		return (ret);
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		ret[0] = '-';
		n = n * (-1);
	}
	while (n)
	{
		len--;
		ret[len] = ((n % 10) + '0');
		n = n / 10;
	}
	return (ret);
}
