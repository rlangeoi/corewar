/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:33:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:07:35 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_printf_per_left(t_flag *f, int len)
{
	ft_putchar('%');
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_printf_per(t_flag *f, int len)
{
	while (f->w > len)
	{
		if (f->flag & FLAG_ZERO)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
	}
	ft_putchar('%');
	return (len);
}

int			ft_conv_per(const char **format, va_list ap, t_flag *f)
{
	int		len;

	(void)ap;
	if (**format == '%')
	{
		len = 1;
		len = (len < f->w && f->flag & FLAG_MINUS) ?
			(ft_printf_per_left(f, len)) : (ft_printf_per(f, len));
		return (len);
	}
	else
		return (0);
}
