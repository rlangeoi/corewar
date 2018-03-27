/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 09:53:07 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:08:38 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_x_left(unsigned long long nbr, t_flag *f, int len)
{
	if (f->flag & FLAG_ALTERNATE && nbr > 0)
	{
		ft_putstr("0x");
		len = len + 2;
		f->pre = f->pre + 2;
	}
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	(nbr == 0 && f->pre == 0) ? len++ : ft_putstr(ft_itoa_base(nbr, 16, 0));
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	if (f->pre == 0 && nbr == 0)
		len = f->w;
	return (len);
}

static int	ft_printf_x(unsigned long long nbr, t_flag *f, int len)
{
	int ret;

	if (f->flag & FLAG_ALTERNATE && nbr != 0)
		len = len + 2;
	if (f->flag & FLAG_ALTERNATE && nbr != 0 && f->pre > -1)
		f->pre = f->pre + 2;
	if (f->pre == 0 && f->w > 0 && nbr == 0)
		f->w++;
	ret = MAX(len, f->pre);
	ret = MAX(ret, f->w);
	if (f->flag & FLAG_ZERO && f->flag & FLAG_ALTERNATE && nbr != 0)
		ft_putstr("0x");
	(f->w)++;
	while (--f->w > f->pre && f->w > len)
		((f->flag & FLAG_ZERO) && (f->pre < 0)) ?
			ft_putchar('0') : ft_putchar(' ');
	if (f->flag & FLAG_ALTERNATE && nbr != 0 && !(f->flag & FLAG_ZERO))
		ft_putstr("0x");
	while (f->pre > len++)
		ft_putchar('0');
	(nbr == 0 && (f->pre == 0)) ?
		ret-- : ft_putstr(ft_itoa_base(nbr, 16, 0));
	if (nbr == 0 && f->pre == 0 && ret == 0)
		ret = -2;
	return (ret);
}

int			ft_conv_x(const char **format, va_list ap, t_flag *f)
{
	int					len;
	unsigned long long	nbr;

	if (**format == 'x')
	{
		if (f->mod & MOD_HH)
			nbr = (unsigned char)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_H)
			nbr = (unsigned short)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_L)
			nbr = (unsigned long)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_LL || f->mod & MOD_Z || f->mod & MOD_J)
			nbr = va_arg(ap, unsigned long long);
		else
			nbr = (unsigned int)va_arg(ap, unsigned long long);
		len = (int)ft_numlen_base(nbr, 16);
		len = (len < f->w && (FLAG_MINUS & f->flag)) ?
			(ft_printf_x_left(nbr, f, len)) : (ft_printf_x(nbr, f, len));
		return (len);
	}
	else
		return (0);
}
