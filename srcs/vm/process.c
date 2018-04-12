/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:56:35 by                   #+#    #+#             */
/*   Updated: 2018/04/08 21:41:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_parse_instruction(t_vm *data, t_proc *process)
{
	if (data->ram[process->pc] >= 1 && data->ram[process->pc] <= 16)
	{
		process->opcode = data->ram[process->pc];
		process->duration = op_tab[(int)process->opcode].cycles - 1;
		ft_printf("Parsed mem : opcode = %d, duration = %d\n", process->opcode, process->duration);
	}
	else
	{
		ft_printf("PROUBLAIME, pc %d", process->pc);
		process->pc2 = ++(process->pc);
		ft_printf(" pc %d\n", process->pc);
	}
}

void	ft_process(t_vm *data, t_proc *process)
{
	if (--process->at_cycle == 0)
		ft_printf("blah\n");
	else if (process->opcode == -1)
		ft_parse_instruction(data, process);
}

