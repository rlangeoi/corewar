/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:13:16 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/26 15:04:54 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	if (!str || !(*str))
		return ;
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
}
