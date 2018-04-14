/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:25:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 19:16:52 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ldi(t_vm *data, t_proc *process)
{
	int	value[2];
	int	adress_to_load;

	if (is_reg(process, 2))
	{
		value[0] = get_param(0, data, process);
		value[1] = get_param(1, data, process);
		if (value[0] != -1 && value[1] != -1)
		{
			adress_to_load = circular_mem(PC + ((value[0] + value[1]) % IDX_MOD));
			REG(2) = ft_ramcpy(data, 4, adress_to_load);
			process->carry = REG(2) ? 0 : 1;
			if (verbose_operations(data))
			{
				ft_printf("P %4d | ldi %d %d r%d\n", ID, value[0], value[1], PARAM(2));
				ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
					value[0], value[1], value[0] + value[1], PC + (value[0] + value[1]) % IDX_MOD);
			}
		}
	}
	advance_pc(data, process);
}
