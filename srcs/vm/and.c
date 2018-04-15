/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:04:54 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 18:33:07 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_and(t_vm *data, t_proc *process)
{
	int param_value[2];

	if (is_reg(process, 2))
	{
		param_value[0] = get_param(0, data, process);
		param_value[1] = get_param(1, data, process);
		REG(2) = param_value[0] & param_value[1];
		process->carry = REG(2) ? 0 : 1;
		if (verbose_operations(data))
			ft_printf("P% 5d | and %d %d r%d\n", ID, param_value[0], param_value[1],
				PARAM(2));
	}
	advance_pc(data, process);
}
