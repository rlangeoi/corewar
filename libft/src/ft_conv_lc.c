/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:48:01 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:06:03 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_lc_left(wchar_t c, t_flag *f, int len)
{
	if (!(c == 0))
		ft_putnwstr(&c, len);
	else
		ft_putchar('\0');
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_printf_lc(wchar_t c, t_flag *f, int len)
{
	int ret;

	ret = 0;
	while (f->w > len)
	{
		if (f->flag & FLAG_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		f->w--;
		ret++;
	}
	ret = ret + len;
	if (c != 0)
		ft_putnwstr(&c, len);
	else
		ft_putchar('\0');
	return (ret);
}

int			ft_conv_lc(const char **format, va_list ap, t_flag *f)
{
	wchar_t	c;
	int		len;

	if ((**format == 'c' && f->mod & MOD_L) || **format == 'C')
	{
		c = (wchar_t)va_arg(ap, wint_t);
		len = ft_wcharlen(c);
		if (len == -1)
			return (-1);
		len = (len < f->w && f->flag & FLAG_MINUS) ?
			(ft_printf_lc_left(c, f, len)) : (ft_printf_lc(c, f, len));
		return (len);
	}
	else
		return (0);
}
