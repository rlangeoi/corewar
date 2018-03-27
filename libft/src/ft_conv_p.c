/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:31:32 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:07:17 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_printf_p_left(unsigned long long nbr, t_flag *f, int len)
{
	ft_putstr("0x");
	len = len + 2;
	if (nbr == 0 && f->pre == 0)
		len--;
	if (f->pre > -1)
		f->pre = f->pre + 2;
	while (f->pre > len)
	{
		ft_putchar('0');
		len++;
	}
	if (!(nbr == 0 && ((f->pre == 2))))
		ft_putstr(ft_itoa_base(nbr, 16, 0));
	while (len < f->w)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int	ft_printf_p(unsigned long long nbr, t_flag *f, int len)
{
	int ret;

	len = len + 2;
	if (f->pre > -1)
		f->pre = f->pre + 2;
	ret = MAX(len, f->pre);
	ret = MAX(ret, f->w);
	if (f->flag & FLAG_ZERO)
		ft_putstr("0x");
	while (f->w > f->pre && f->w > len)
	{
		((f->flag & FLAG_ZERO) && (f->pre < 0)) ?
			ft_putchar('0') : ft_putchar(' ');
		(f->w)--;
	}
	if (!(f->flag & FLAG_ZERO))
		ft_putstr("0x");
	while (f->pre > len++)
		ft_putchar('0');
	(nbr == 0 && (f->pre == 2)) ?
		ret = 2 : ft_putstr(ft_itoa_base(nbr, 16, 0));
	return (ret);
}

int			ft_conv_p(const char **format, va_list ap, t_flag *f)
{
	int					len;
	unsigned long long	nbr;

	if (**format == 'p')
	{
		nbr = (unsigned long long)va_arg(ap, unsigned long long);
		len = (int)ft_numlen_base(nbr, 16);
		len = (len < f->w && (FLAG_MINUS & f->flag)) ?
			(ft_printf_p_left(nbr, f, len)) : (ft_printf_p(nbr, f, len));
		if (f->pre == 0 && nbr == 0 && f->w == 0 && !(f->flag & FLAG_ALTERNATE))
			return (-2);
		return (len);
	}
	else
		return (0);
}
