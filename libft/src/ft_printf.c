/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:25:20 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/11/01 19:47:43 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>

int		ft_printf(const char *format, ...)
{
	t_flag	*f;
	int		end;
	va_list	ap;

	f = NULL;
	va_start(ap, format);
	end = 1;
	while (end)
	{
		f = ft_init_flag(f);
		end = ft_printf_format(&format, f);
		if (end)
			(f->n) = (f->n) + ft_printf_parse(&format, ap, f);
	}
	free(f);
	f = NULL;
	if (f != NULL)
		return (f->n);
	else
		return (-1);
}

void	ft_init_ftptr(t_flag *f)
{
	f->p_conv[0] = ft_conv_d;
	f->p_conv[1] = ft_conv_u;
	f->p_conv[2] = ft_conv_o;
	f->p_conv[3] = ft_conv_x;
	f->p_conv[4] = ft_conv_lx;
	f->p_conv[5] = ft_conv_lc;
	f->p_conv[6] = ft_conv_c;
	f->p_conv[7] = ft_conv_s;
	f->p_conv[8] = ft_conv_ls;
	f->p_conv[9] = ft_conv_per;
	f->p_conv[10] = ft_conv_b;
	f->p_conv[11] = ft_conv_p;
}

t_flag	*ft_init_flag(t_flag *f)
{
	if (f == NULL)
	{
		if (!(f = (t_flag*)malloc(sizeof(t_flag))))
			exit(EXIT_FAILURE);
		f->n = 0;
		ft_init_ftptr(f);
	}
	f->w = 0;
	f->pre = -1;
	f->mod = 0;
	f->flag = 0;
	return (f);
}

int		ft_printf_format(const char **format, t_flag *f)
{
	if (**format == '\0')
		return (0);
	while (**format != '%' && **format != '\0')
	{
		ft_putchar(**format);
		(f->n)++;
		(*format)++;
	}
	if (**format == '%')
	{
		(*format)++;
	}
	return (1);
}
