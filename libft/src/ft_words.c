/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:44 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:36:46 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(const char *str, char c)
{
	int wds;

	if (!(*str))
		return (0);
	while (*str == c)
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	wds = 1;
	while (*str != '\0')
	{
		if (*str == c)
		{
			while (*(str + 1) == c)
				str++;
			wds++;
		}
		str++;
	}
	if (*(str - 1) == c)
		wds--;
	return (wds);
}
