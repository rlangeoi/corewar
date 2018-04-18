/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/18 17:43:55 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				ft_dump_data(t_vm *data)
{
	int	reader;
	int offset;

	reader = -1;
	offset = 0;
	while (++reader < MEM_SIZE)
	{
		if (reader % 64 == 0)
		{
			offset == 0 ? ft_printf("0x%#.4x : ", offset) :\
					ft_printf("\n%#.4x : ", offset);
			offset = offset + 64;
		}
		ft_printf("%.2x ", (unsigned char)data->ram[reader]);
	}
	ft_printf("\n");
}

int				ft_ramcpy(t_vm *data, int size, int pc)
{
	int	arg;

	arg = 0;
	while (pc < 0)
		pc += MEM_SIZE;
	if (size == 1)
		arg = data->ram[pc % MEM_SIZE];
	else if (size == 2)
	{
		arg = data->ram[(pc + 1) % MEM_SIZE];
		arg |= ((data->ram[pc % MEM_SIZE]) << 8);
	}
	else
	{
		arg = data->ram[(pc + 3) % MEM_SIZE];
		arg |= ((data->ram[(pc + 2) % MEM_SIZE]) << 8);
		arg |= ((data->ram[(pc + 1) % MEM_SIZE]) << 16);
		arg |= ((data->ram[pc % MEM_SIZE]) << 24);
	}
	return (arg);
}

unsigned int	switch_endianness(unsigned int bytes)
{
	return ((bytes >> 24) + (((bytes << 8) >> 24) << 8) +
			(((bytes << 16) >> 24) << 16) + (bytes << 24));
}
