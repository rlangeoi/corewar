/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:50:04 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/11/01 19:30:58 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_nullificator(int *len)
{
	char *s;

	s = ft_strnew(7);
	ft_strcpy(s, "(null)");
	*len = 6;
	free(s);
	s = NULL;
	return (s);
}

static int	ft_printf_s_left(char *s, t_flag *f, int len)
{
	int ret;

	if (f->pre != -1)
		len = MIN(len, f->pre);
	ret = MAX(len, f->w);
	ft_putnstr(s, len);
	while (f->w > len)
	{
		f->w--;
		ft_putchar(' ');
	}
	return (ret);
}

static int	ft_printf_s(char *s, t_flag *f, int len)
{
	int ret;

	if (f->pre != -1)
		len = MIN(len, f->pre);
	ret = MAX(len, f->w);
	while (f->w > len)
	{
		(f->flag & FLAG_ZERO) ? (ft_putchar('0')) : (ft_putchar(' '));
		f->w--;
	}
	ft_putnstr(s, len);
	return (ret);
}

int			ft_conv_s(const char **format, va_list ap, t_flag *f)
{
	int		len;
	char	*s;

	if (**format == 's' && !(f->mod & MOD_L))
	{
		s = va_arg(ap, char *);
		if (s && *s)
			len = (int)ft_strlen(s);
		else
			len = 0;
		if (!s)
			s = ft_nullificator(&len);
		len = ((f->flag & FLAG_MINUS) == 0) ?
			(ft_printf_s(s, f, len)) : (ft_printf_s_left(s, f, len));
		return (len == 0 ? (-2) : (len));
	}
	else
		return (0);
}
