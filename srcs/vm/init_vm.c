/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:41:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/08 19:58:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static t_proc	*ft_mkproc(int pnum)
{
	t_proc		*the_process;

	if (!(the_process = (t_proc*)malloc(sizeof(t_proc))))
		return (NULL);
	the_process->num = pnum;
	the_process->player = 0;
	the_process->opcode = -1;
	the_process->ocp = 0;
	the_process->pc2 = 0;
	the_process->header = NULL;
	the_process->pc = 0;
	ft_bzero(&the_process->reg[1], (REG_SIZE * REG_NUMBER) - 1);
	ft_bzero(&the_process->param[0], sizeof(int) * 3);
	ft_bzero(&the_process->arg_type[0], (sizeof(t_arg_type) * 3));
	the_process->reg[REG_SIZE - 1] = (char)pnum;
	return (the_process);
}

t_list			*ft_add_process(t_list *processes, int pnum)
{
	t_list	*new;
	t_proc	*process;

	if (!(process = ft_mkproc(pnum)))
		return (NULL);
	if (!(new = (t_list*)ft_lstnew((void*)process, (sizeof(t_proc)))))
		return (NULL);
	if (processes == NULL)
		return (new);
	else
		ft_lstadd(&processes, new);
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
