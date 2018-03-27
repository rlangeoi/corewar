/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 08:16:48 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:07:00 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_o_left(unsigned long long nbr, t_flag *f, int len)
{
	if (f->flag & FLAG_ALTERNATE)
	{
		ft_putchar('0');
		if (nbr != 0)
			len++;
	}
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	if (!(nbr == 0 && ((f->pre == 0) || (f->flag & FLAG_ALTERNATE))))
		ft_putstr(ft_itoa_base(nbr, 8, 0));
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	if (f->pre == 0 && nbr == 0)
		len = f->w;
	if (len == 0)
		return (-2);
	return (len);
}

static int	ft_printf_o(unsigned long long nbr, t_flag *f, int len)
{
	int ret;

	if (f->flag & FLAG_ALTERNATE && nbr != 0)
		len++;
	if (nbr == 0 && f->pre == 0)
		f->w++;
	ret = MAX(len, f->pre);
	ret = MAX(ret, f->w);
	while (f->w > f->pre && f->w > len)
	{
		if ((f->flag & FLAG_ZERO) && (f->pre < 0))
			ft_putchar('0');
		else
			ft_putchar(' ');
		(f->w)--;
	}
	if (f->flag & FLAG_ALTERNATE && !(nbr == 0))
		ft_putchar('0');
	while (f->pre > len++)
		ft_putchar('0');
	(nbr == 0 && ((f->pre == 0) && !(f->flag & FLAG_ALTERNATE))) ?
		ret-- : ft_putstr(ft_itoa_base(nbr, 8, 0));
	if (nbr == 0 && ret == 0 && f->pre == 0 && !(f->flag & FLAG_ALTERNATE))
		ret = -2;
	return (ret);
}

int			ft_conv_o(const char **format, va_list ap, t_flag *f)
{
	int					len;
	unsigned long long	nbr;

	if (**format == 'o' || **format == 'O')
	{
		if (**format != 'O' && f->mod & MOD_HH)
			nbr = (unsigned char)va_arg(ap, unsigned long long);
		else if (**format != 'O' && f->mod & MOD_H)
			nbr = (unsigned short)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_L || (**format == 'O'))
			nbr = (unsigned long)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_LL || f->mod & MOD_Z || f->mod & MOD_J)
			nbr = va_arg(ap, unsigned long long);
		else
			nbr = (unsigned int)va_arg(ap, unsigned long long);
		len = (int)ft_numlen_base(nbr, 8);
		len = (len < f->w && (FLAG_MINUS & f->flag)) ?
			(ft_printf_o_left(nbr, f, len)) : (ft_printf_o(nbr, f, len));
		return (len);
	}
	else
		return (0);
}
