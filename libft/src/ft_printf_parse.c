/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:25:46 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:09:15 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printf_parse(const char **format, va_list ap, t_flag *f)
{
	int			ret;
	int			i;
	const char	*ptr;

	ret = 0;
	i = 0;
	ft_printf_conv(format, f, ap);
	ptr = (*format);
	while (**format && !ret)
	{
		while (!ret && i < NB_CONV)
		{
			ret = (f->p_conv[i])(format, ap, f);
			i++;
		}
		(*format)++;
	}
	if (ret == 0)
		(*format) = ptr;
	if (ret == -2)
		return (0);
	else
		return (ret);
}

void	ft_printf_conv(const char **format, t_flag *f, va_list ap)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
			**format == ' ' || **format == '+' || **format == '\'')
		ft_printf_flags(format, f);
	while ((**format >= '0' && **format <= '9') || **format == '*')
	{
		if (**format >= '0' && **format <= '9')
			f->w = ft_atoi(*format);
		else
			ft_printf_ast_fw(format, f, ap);
		while (**format <= 32 || (**format >= '0' && **format <= '9'))
			(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
			ft_printf_ast_pre(format, f, ap);
		else
			f->pre = ft_atoi(*format);
		while (**format <= 32 || (**format >= '0' && **format <= '9')
				|| **format == '*')
			(*format)++;
	}
	ft_printf_mod(format, f);
}

void	ft_printf_flags(const char **format, t_flag *f)
{
	while (**format == '#' || **format == '0' || **format == '-' ||
			**format == ' ' || **format == '+' || **format == '\'')
	{
		if (**format == '#' && !(f->flag & FLAG_ALTERNATE))
			f->flag += FLAG_ALTERNATE;
		else if (**format == '0' && !(f->flag & FLAG_ZERO))
			f->flag += FLAG_ZERO;
		else if (**format == '-' && !(f->flag & FLAG_MINUS))
			f->flag += FLAG_MINUS;
		else if (**format == ' ' && !(f->flag & FLAG_SPACE))
			f->flag += FLAG_SPACE;
		else if (**format == '+' && !(f->flag & FLAG_PLUS))
			f->flag += FLAG_PLUS;
		(*format)++;
	}
}

void	ft_printf_mod(const char **format, t_flag *f)
{
	while (**format == 'h' || **format == 'l' || **format == 'L' ||
			**format == 'z' || **format == 'j')
	{
		if (**format == 'h')
		{
			if (f->mod == MOD_H)
				f->mod = MOD_HH;
			else if (f->mod == 0)
				f->mod = MOD_H;
		}
		else if (**format == 'l')
		{
			if (f->mod == MOD_L)
				f->mod = MOD_LL;
			else if (f->mod == 0)
				f->mod = MOD_L;
		}
		else if (**format == 'j' && f->mod == 0)
			f->mod = MOD_J;
		else if (**format == 'z' && f->mod == 0)
			f->mod = MOD_Z;
		(*format)++;
	}
}
