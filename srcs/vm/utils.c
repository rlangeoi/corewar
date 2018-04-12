/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/12 17:05:11 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				ft_ramcpy(t_vm *data, int size, int pc)
{
	int	arg;

	arg = 0;
	if (size == 1)
		arg = data->ram[pc % MEM_SIZE];
	else if (size == 2)
	{
		arg = data->ram[(pc + 1) % MEM_SIZE];
		arg |= data->ram[pc % MEM_SIZE];
	}
	else
	{
		arg = switch_endianness((unsigned int)(data->ram[pc % MEM_SIZE]));
	}
	return (arg);
}

unsigned int	switch_endianness(unsigned int bytes)
{
	return ((bytes >> 24) + (((bytes << 8) >> 24) << 8) +
			(((bytes << 16) >> 24) << 16) + (bytes << 24));
}
