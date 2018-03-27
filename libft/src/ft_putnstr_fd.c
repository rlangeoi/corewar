/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:10:38 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/02/26 15:04:33 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(const char *str, int len, int fd)
{
	int i;

	i = 0;
	if (!str || str == NULL || fd == -1)
		return ;
	while (i < len && *str != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
