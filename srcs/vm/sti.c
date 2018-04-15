/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:09:44 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 18:55:29 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_sti(t_vm *data, t_proc *process)
{
	int	value[2];
	int	address;

	if (is_reg(process, 0))
	{
		value[0] = get_param(1, data, process);
		value[1] = get_param(2, data, process);
		address = circular_mem(PC + ((value[0] + value[1]) % IDX_MOD));
		store_reg(data, address, REG(0));
	//	process->carry = REG(0) ? 0 : 1 ;
		if (verbose_operations(data))
		{
			ft_printf("P %4d | sti r%d %d %d\n", ID, (short)PARAM(0), value[0], value[1]);
			ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				value[0], value[1], value[0] + value[1], PC + (value[0] + value[1]) % IDX_MOD);
		}
	}
	advance_pc(data, process);
}
