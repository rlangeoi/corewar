/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 03:07:06 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/11/01 16:38:54 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_positifator(long long *nbr, t_flag *f)
{
	int len;

	len = 0;
	if ((*nbr >= 0) && ((f->flag & FLAG_PLUS) || (f->flag & FLAG_SPACE)))
	{
		if (f->flag & FLAG_SPACE && !(f->flag & FLAG_PLUS))
			ft_putchar(' ');
		if (f->flag & FLAG_PLUS)
			ft_putchar('+');
		len++;
		if (f->pre >= 0)
			(f->pre)++;
	}
	else if ((*nbr) < 0)
	{
		*nbr = (*nbr) * -1;
		ft_putchar('-');
		if (f->pre >= 0)
			(f->pre)++;
	}
	return (len);
}

static int	ft_printf_d_left(long long nbr, t_flag *f, int len)
{
	len = len + ft_positifator(&nbr, f);
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	if (!(f->pre == 0 && nbr == 0))
		ft_putnbr(nbr);
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	f->n = len;
	return (len);
}

static int	ft_printf_d(long long nbr, t_flag *f, int len)
{
	int ret;

	if ((f->w <= len && nbr != LONG_MIN) || f->flag & FLAG_ZERO)
		len = len + ft_positifator(&nbr, f);
	ret = MAX(len, f->pre);
	ret = MAX(ret, f->w);
	if (f->pre == 0 && nbr == 0 && f->w != 0)
		f->w++;
	if (f->pre > 0 && f->w < f->pre && nbr < 0)
		ret++;
	if ((f->pre > len && nbr < 0) ||
			(f->w > f->pre && f->pre > 0 && nbr > 0 && f->flag & FLAG_PLUS))
		(f->w)--;
	(f->w)++;
	while (--f->w > f->pre && f->w > len)
		((f->flag & FLAG_ZERO) && (f->pre < 0)) ?
			ft_putchar('0') : ft_putchar(' ');
	if (f->w && f->pre > 0 && nbr > 0 && f->flag & FLAG_PLUS)
		ft_putchar('+');
	if (f->pre > len && nbr < 0)
		ft_positifator(&nbr, f);
	while (f->pre > len++)
		ft_putchar('0');
	(nbr == 0 && f->pre == 0) ? nbr = (int)12052 : ft_putnbr(nbr);
	return (ret);
}

int			ft_conv_d(const char **format, va_list ap, t_flag *f)
{
	int				len;
	long long int	nbr;

	if (**format == 'd' || **format == 'D' || **format == 'i')
	{
		if (**format != 'D' && f->mod & MOD_HH)
			nbr = (signed char)va_arg(ap, long long int);
		else if (**format != 'D' && f->mod & MOD_H)
			nbr = (short)va_arg(ap, long long int);
		else if ((f->mod & MOD_L) || **format == 'D')
			nbr = (long)va_arg(ap, long long int);
		else if (f->mod & MOD_LL || f->mod & MOD_Z || f->mod & MOD_J)
			nbr = va_arg(ap, long long int);
		else
			nbr = (int)va_arg(ap, long long);
		len = (int)ft_numlen(nbr);
		len = (len < f->w && f->w > f->pre && (FLAG_MINUS & f->flag)) ?
			(ft_printf_d_left(nbr, f, len)) : (ft_printf_d(nbr, f, len));
		if (f->pre == 0 && f->w == 0 && nbr == 0)
			return (-2);
		return (len);
	}
	else
		return (0);
}
