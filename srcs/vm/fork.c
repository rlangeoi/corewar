/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:19:23 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 19:58:42 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		copy_process(t_vm *data, t_proc *process, t_process *copy)
{
	int	nb;

	nb = REG_NUMBER;
	while (nb--)
		copy->reg[nb] = process->reg[nb];
	copy->id_champ = process->id_champ;
	copy->pc = circular_mem(PC + PARAM(0));
	copy->id = data->nb_process++;
	copy->header = process->header;
	copy->carry = process->carry;
	copy->cycles_wo_live = process->cycles_wo_live;
	copy->color = process->color;
	ft_lstadd(&data->processes, ft_lstnew(copy, sizeof(t_proc)));
}

static t_proc	*create_new_process()
{
	int	par_nb;
	t_proc *process;

	par_nb = -1;
	if (!(process = (t_proc*)malloc(sizeof(t_process))))
		ft_exit_malloc_error();
	while (++par_nb < 3)
	{
		PARAM(par_nb) = 0;
		PARAM_TYPE(par_nb) = 0;
	}
	process->cycle_bf_exe = 0;
	process->opcode = -1;
	return (process);
}

void			my_fork(t_vm *data, t_proc *process)
{
	t_proc	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + (PARAM(0) % IDX_MOD));
	copy_process(data, process, copy);
	if (verbose_operations(data))
		ft_printf("P% 5d | fork %hd (%d)\n", ID, PARAM(0), PC + (short)PARAM(0) % IDX_MOD);
	advance_pc(data, process);
}

void			my_lfork(t_vm *data, t_proc *process)
{
	t_proc	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + PARAM(0));
	copy_process(data, process, copy);
	if (verbose_operations(data))
		ft_printf("P% 5d | lfork %hd (%d)\n", ID, PARAM(0), PC + (short)PARAM(0));
	advance_pc(data, process);
}
