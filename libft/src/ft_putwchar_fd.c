/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:48:21 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/24 17:35:36 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c < 0x80)
		ft_putchar_fd(c, fd);
	else if (c < 0x800)
	{
		ft_putchar_fd(((c >> 6) + 0xC0), fd);
		ft_putchar_fd(((c & 0x3F) + 0x80), fd);
	}
	else if (c < 0x10000)
	{
		ft_putchar_fd(((c >> 12) + 0xE0), fd);
		ft_putchar_fd((((c >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd(((c & 0x3F) + 0x80), fd);
	}
	else if (c < 0x110000)
	{
		ft_putchar_fd(((c >> 18) + 0xF0), fd);
		ft_putchar_fd((((c >> 12) & 0x3F) + 0x80), fd);
		ft_putchar_fd((((c >> 6) & 0x3F) + 0x80), fd);
		ft_putchar_fd(((c & 0x3F) + 0x80), fd);
	}
	else
		return (-1);
	return (0);
}
