/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:36:12 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/11/01 21:20:31 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(const char *str, char c)
{
	int i;

	i = 1;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		wds;
	int		i;
	char	**supercool;

	if (!(s))
		exit(EXIT_FAILURE);
	wds = ft_words(s, c);
	if (!(supercool = (char**)malloc(sizeof(char*) * (wds + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < wds)
	{
		while (*s == c)
			s++;
		supercool[i] = ft_strsub(s, 0, (ft_wordlen(s, c) - 1));
		i++;
		while (*s != c && *s != '\0')
			s++;
	}
	supercool[i] = 0;
	return (supercool);
}
