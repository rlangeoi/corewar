/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:39:15 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:41:01 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		buffer_start;
	int		buffer_end;
	char	*ptr_end;
	char	*ptr_start;

	ptr_end = str;
	ptr_start = str;
	while (*ptr_end != '\0')
	{
		ptr_end++;
	}
	ptr_end--;
	while (ptr_start < ptr_end)
	{
		buffer_start = *ptr_start;
		buffer_end = *ptr_end;
		*ptr_start = buffer_end;
		*ptr_end = buffer_start;
		ptr_end--;
		ptr_start++;
	}
	return (str);
}
