/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:15:30 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/13 19:27:34 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		ft_arg_types(t_vm *data, t_proc *process)
{
	int i;
	int ret;
	
	process->ocp = data->ram[process->reader % MEM_SIZE];
	process->arg_type[0] = data->ram[process->reader % MEM_SIZE] >> 6;
	process->arg_type[1] = (data->ram[process->reader % MEM_SIZE] & 48) >> 4;
	process->arg_type[2] = (data->ram[process->reader % MEM_SIZE] & 12) >> 2;
	i = -1;
	ret = 2;
	while (++i < op_tab[(int)process->opcode].ac)
	{
		if (process->arg_type[i] == REG_CODE &&
				op_tab[(int)process->opcode].av[i] & T_REG)
			process->reader++;
		else if (process->arg_type[i] == DIR_CODE &&
				op_tab[(int)process->opcode].av[i] & T_DIR)
			process->reader++;
		else if (process->arg_type[i] == IND_CODE &&
				op_tab[(int)process->opcode].av[i] & T_IND)
			process->reader++;
		else
			ret = -2147483648;
	}
	return (ret > 0 ? ret : 0);
}

static void		ft_args_cpy(t_vm *data, t_proc *process)
{
	int	i;

	i = -1;
	while (++i < op_tab[(int)process->opcode].ac)
	{
		if (process->arg_type[i] == 2 &&
				op_tab[(int)process->opcode].label_size == 0)
		{
			process->av[i] = ft_ramcpy(data, 4, process->reader);
			process->reader = process->reader + 4;
		}
		else if (process->arg_type[i] == 1)
		{
			process->av[i] = ft_ramcpy(data, 1, process->reader);
			(process->reader)++;
		}
		else
		{
			process->av[i] = ft_ramcpy(data, 2, process->reader);
			process->reader = process->reader + 2;
		}
	}
}

static int		ft_get_args(t_vm *data, t_proc *process)
{
	int ret;

	process->reader = process->pc + 1;
	if (op_tab[(int)process->opcode].ocp)
	{
		if ((ret = ft_arg_types(data, process)))
			return (ret);
	}
	else
	{
		ret = LAB_SIZE;
		process->av[0] = ft_ramcpy(data,
				ret, process->reader);
		process->reader = process->reader + ret;
		return (0);
	}
	process->reader++;
	ft_args_cpy(data, process);
	return (0);
}

static void		ft_parse_instruction(t_vm *data, t_proc *process)
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
		process->reader = ++(process->pc);
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
		data->f[(int)process->opcode](data, process);
		process->pc = process->reader;
		}
		process->opcode = -1;
	}
	else if (process->opcode == -1)
		ft_parse_instruction(data, process);
}
