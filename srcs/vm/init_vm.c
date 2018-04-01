/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:41:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/01 18:31:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		ft_empty_process(t_proc *the_process)
{
	the_process->player = 0;
	the_process->instruction = 0;
	the_process->ocp = 0;
	ft_bzero(&the_process->reg[0], REG_SIZE * REG_NUMBER);
	ft_bzero(&the_process->pc[0], REG_SIZE);
	return (0);
}

static t_proc	*ft_mkproc()
{
	t_proc		*the_process;

	if (!(the_process = (t_proc*)malloc(sizeof(t_proc))))
		return (NULL);
	return (the_process);
}

t_list			*ft_add_process(t_list *processes)
{
	t_list	*new;
	t_proc	*process;

	if (!(process = ft_mkproc()))
		return (NULL);
	if (!(new = (t_list*)ft_lstnew((void*)process, (sizeof(t_proc)))))
		return (NULL);
	if (ft_empty_process(process))
		return (NULL);
	if (processes == NULL)
		return (new);
	else
		processes = ft_lstadd_end(&processes, new);
	return (processes);
}

void			ft_init_vm(t_vm *data)
{
	int	i;

	i = -1;
	data->nb_players = 0;
	data->dump = -1;
	data->flags = NO_FLAG;
	data->verbose = 0;
	data->cycles = 0;
	data->players_alive = 0;
	data->cycle_reduction = 0;
	data->processes = NULL;
	data->checks = 0;
	data->headers = NULL;
	ft_bzero((void*)data->ram, MEM_SIZE);
	while (++i < 4)
		ft_bzero((void*)data->players[i], CHAMP_MAX_SIZE);
}
