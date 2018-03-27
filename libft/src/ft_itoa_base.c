/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:31:28 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:09:58 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_itoa_base(unsigned long long n, unsigned int base, int maj)
{
	size_t	len;
	char	*ret;

	if (base < 2 || base > 36)
		return (NULL);
	len = ft_numlen_base(n, base);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		len--;
		if ((n % base) < 10)
			ret[len] = ((n % base) + '0');
		else if ((n % base) >= 10)
			ret[len] = (maj) ? ((n % base) + 55) : ((n % base) + 87);
		n = n / base;
	}
	free(ret);
	return (ret);
}
