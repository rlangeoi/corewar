/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 10:22:59 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:09:29 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printf_ast_fw(const char **format, t_flag *f, va_list ap)
{
	int i;

	i = 0;
	i = va_arg(ap, int);
	if (i < 0 && !(f->flag & FLAG_MINUS))
	{
		f->flag += FLAG_MINUS;
		i = i * -1;
	}
	f->w = i;
	(*format)++;
}

void	ft_printf_ast_pre(const char **format, t_flag *f, va_list ap)
{
	int i;

	i = 0;
	f->flag += FLAG_AST;
	i = va_arg(ap, int);
	if (i >= 0)
		f->pre = i;
	(*format)++;
}
