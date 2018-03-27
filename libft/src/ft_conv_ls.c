/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:07:39 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:06:18 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static wchar_t	*ft_nullificator(int *len)
{
	wchar_t *s;

	s = L"(null)";
	*len = 6;
	return (s);
}

static int		ft_printf_ls_left(wchar_t *s, t_flag *f, int len)
{
	int ret;

	if (f->pre != -1)
		len = MIN(len, f->pre);
	ret = MAX(len, f->w);
	len = ft_putnwstr(s, len);
	while (f->w > len)
	{
		f->w--;
		ft_putchar(' ');
	}
	return (ret);
}

static int		ft_printf_ls(wchar_t *s, t_flag *f, int len)
{
	int ret;

	if (f->pre != -1)
		len = MIN(len, f->pre);
	len = ft_nwstrlen(s, len);
	ret = MAX(len, f->w);
	while (f->w > len)
	{
		(f->flag & FLAG_ZERO) ? (ft_putchar('0')) : (ft_putchar(' '));
		f->w--;
	}
	len = ft_putnwstr(s, len);
	return (ret);
}

int				ft_conv_ls(const char **format, va_list ap, t_flag *f)
{
	int		len;
	wchar_t	*s;

	if ((**format == 's' && (f->mod & MOD_L)) || **format == 'S')
	{
		s = (wchar_t *)va_arg(ap, wchar_t *);
		if (s && *s)
			len = (int)ft_wstrlen(s);
		else
			len = 0;
		if (!s)
			s = ft_nullificator(&len);
		len = ((f->flag & FLAG_MINUS) == 0) ?
			(ft_printf_ls(s, f, len)) : (ft_printf_ls_left(s, f, len));
		return (len == 0 ? (-2) : (len));
	}
	else
		return (0);
}
