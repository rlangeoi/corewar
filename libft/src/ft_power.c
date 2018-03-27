/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:19 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:36:21 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	if (power <= 0)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}
