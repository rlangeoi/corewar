/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:44:44 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/07 12:19:21 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_ALTERNATE 1
# define FLAG_ZERO	2
# define FLAG_MINUS	4
# define FLAG_SPACE	8
# define FLAG_PLUS	16
# define FLAG_AST	32
# define MOD_HH	1
# define MOD_H	2
# define MOD_L	4
# define MOD_LL	8
# define MOD_J	16
# define MOD_Z	32
# define NB_CONV 12
# define MAX(X, Y) (((X) >= (Y)) ? (X) : (Y))
# define MIN(X, Y) (((X) <= (Y)) ? (X) : (Y))

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_flag
{
	char			flag;
	char			mod;
	int				w;
	int				pre;
	int				n;
	int				(*p_conv[NB_CONV])(const char**, va_list, struct s_flag*);
}					t_flag;

int					ft_printf(const char *format, ...);
void				ft_init_ftptr(t_flag *f);
t_flag				*ft_init_flag(t_flag *f);
int					ft_printf_format(const char **format, t_flag *f);
int					ft_printf_parse(const char **format, va_list ap, t_flag *f);
void				ft_printf_conv(const char **format, t_flag *f, va_list ap);
void				ft_printf_mod(const char **format, t_flag *f);
void				ft_printf_flags(const char **format, t_flag *f);
int					ft_conv_d(const char **format, va_list ap, t_flag *f);
int					ft_conv_u(const char **format, va_list ap, t_flag *f);
int					ft_conv_o(const char **format, va_list ap, t_flag *f);
int					ft_conv_x(const char **format, va_list ap, t_flag *f);
int					ft_conv_lx(const char **format, va_list ap, t_flag *f);
int					ft_conv_lc(const char **format, va_list ap, t_flag *f);
int					ft_conv_c(const char **format, va_list ap, t_flag *f);
int					ft_conv_s(const char **format, va_list ap, t_flag *f);
int					ft_conv_ls(const char **format, va_list ap, t_flag *f);
int					ft_conv_b(const char **format, va_list ap, t_flag *f);
int					ft_conv_per(const char **format, va_list ap, t_flag *f);
int					ft_conv_p(const char **format, va_list ap, t_flag *f);
void				ft_printf_ast_pre(const char **format, t_flag *f,
		va_list ap);
void				ft_printf_ast_fw(const char **format, t_flag *f,
		va_list ap);
#endif
