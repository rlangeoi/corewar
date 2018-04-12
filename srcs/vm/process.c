/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:56:35 by                   #+#    #+#             */
/*   Updated: 2018/04/12 11:39:34 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		ft_args_cpy(t_vm *data, t_proc *process)
{
	int	i;

	i = -1;
	while (++i < op_tab[process->opcode].ac)
	{
		if (process->arg_type[i] == 2 &&
				op_tab[process->opcode].label_size == 0)
		{
			process->param[i] = ft_ramcpy(data, 4, process->pc2);
			process->pc2 = process->pc2 + 4;
		}
		else if (process->arg_type[i] == 1)
		{
			process->param[i] = ft_ramcpy[i](data, 1, process->pc2);
			(process->pc2)++;
		}
		else
		{
			process->param[i] = ft_load(data, 2, process->pc2);
			process->pc2 = process->pc2 + 2;
		}
	}
}

static int		ft_get_args(t_vm *data, t_proc *process)
{
	int ret;

	process->pc2 = process->pc + 1;
	if (op_tab[process->opcode].ocp)
	{
		if ((ret = ft_get_ocp(data, process)))
			return (ret);
	}
	else
	{
		process->param[0] = ft_ramcpy(data,
				LAB_SIZE(op_tab[process->opcode].label_size), process->pc2);
		process->pc2 = process->pc2 +
			LAB_SIZE(op_tab[process->opcode].label_size, process->pc2);
		return (0);
	}
	process->pc2++;
	ft_args_cpy(data, process);
	return (0);
}

static void		ft_parse_instruction(t_vm *data, t_proc *process)
{
	if (data->ram[process->pc] >= 1 && data->ram[process->pc] <= 16)
	{
		process->opcode = data->ram[process->pc];
	process = (t_proc*)processes->content;
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
	int ret;

	if (--process->at_cycle == 0)
	{
		if ((ret = ft_get_args(data, process)))
			process->pc = process->pc + ret;
		else
		{
		data->ex[(int)process->opcode](data, process);
		process->pc = process->pc2;
		}
	}
	process->opcode = -1;
	else if (process->opcode == -1)
		ft_parse_instruction(data, process);
}

