/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:25:59 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 15:34:00 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		ft_load(t_vm *data, int size, int adress)
{
	int		param;

	param = 0;
	while (adress < 0)
		adress += MEM_SIZE;
	if (size == 1)
		param = data->ram[(adress) % MEM_SIZE];
	else if (size == 2)
	{
		param = ((data->ram[(adress + 1) % MEM_SIZE]));
		param |= ((data->ram[(adress + 0) % MEM_SIZE]) << 8);
	}
	else
	{
		param = ((data->ram[(adress + 3) % MEM_SIZE]));
		param |= ((data->ram[(adress + 2) % MEM_SIZE]) << 8);
		param |= ((data->ram[(adress + 1) % MEM_SIZE]) << 16);
		param |= ((data->ram[(adress + 0) % MEM_SIZE]) << 24);
	}
	return (param);
}
