/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:16:35 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/25 15:29:21 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnwstr_fd(wchar_t *str, int fd, int len)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (!str || !(*str))
		return (-1);
	while (*str && i < len)
	{
		i = i + ft_wcharlen(*str);
		if (i <= len)
		{
			ft_putwchar_fd(*str, fd);
			ret = i;
		}
		str++;
	}
	return (ret);
}
