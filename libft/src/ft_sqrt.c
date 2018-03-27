/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:26 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:36:27 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int buffer;
	int result;

	buffer = 0;
	result = 0;
	if (nb > 2147395600)
		return (0);
	while (buffer <= nb)
	{
		buffer = result * result;
		if (buffer == nb)
			return (result);
		result++;
	}
	return (0);
}
