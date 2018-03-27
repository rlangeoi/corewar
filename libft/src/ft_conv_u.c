/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 06:12:49 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:08:26 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_u_left(unsigned long long nbr, t_flag *f, int len)
{
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	if (!(f->pre == 0 && nbr == 0))
		ft_putunbr(nbr);
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	f->n = len;
	if (f->pre == 0 && nbr == 0)
		len = f->w;
	return (len);
}

static int	ft_printf_u(unsigned long long nbr, t_flag *f, int len)
{
	int ret;

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
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	if (!(nbr == 0 && f->pre == 0))
		ft_putunbr(nbr);
	return (ret);
}

int			ft_conv_u(const char **format, va_list ap, t_flag *f)
{
	int				len;
	long long int	nbr;

	if (**format == 'u' || **format == 'U')
	{
		if (f->mod & MOD_HH && **format != 'U')
			nbr = (unsigned char)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_H && **format != 'U')
			nbr = (unsigned short)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_L || **format == 'U')
			nbr = (unsigned long)va_arg(ap, unsigned long long);
		else if (f->mod & MOD_LL || f->mod & MOD_Z || f->mod & MOD_J)
			nbr = va_arg(ap, unsigned long long);
		else
			nbr = (unsigned int)va_arg(ap, unsigned long long);
		len = (int)ft_numlen_base(nbr, 10);
		len = (len < f->w && (FLAG_MINUS & f->flag)) ?
			(ft_printf_u_left(nbr, f, len)) : (ft_printf_u(nbr, f, len));
		if (f->pre == 0 && nbr == 0 && f->w == 0)
			return (-2);
		return (len);
	}
	else
		return (0);
}
