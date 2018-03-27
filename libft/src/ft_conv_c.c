/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:27:08 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:05:21 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_printf_c_left(char c, t_flag *f, int len)
{
	ft_putchar(c);
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_printf_c(char c, t_flag *f, int len)
{
	while (f->w > len)
	{
		if (f->flag & FLAG_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
	}
	ft_putchar(c);
	return (len);
}

int			ft_conv_c(const char **format, va_list ap, t_flag *f)
{
	wchar_t	c;
	int		len;

	if (**format == 'c' && !(f->mod & MOD_L))
	{
		c = (char)va_arg(ap, int);
		len = 1;
		len = (len < f->w && f->flag & FLAG_MINUS) ?
			(ft_printf_c_left(c, f, len)) : (ft_printf_c(c, f, len));
		return (len);
	}
	else
		return (0);
}
