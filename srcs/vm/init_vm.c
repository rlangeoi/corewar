/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:41:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/30 12:30:23 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_empty_process(t_proc the_process)
{
	the_process->player = 0;
	the_process->instruction = 0;
	the_process->ocp = 0;
	ft_bzero(&reg[0], REG_SIZE * REG_NUMBER);
	ft_bzero(&pc[0], REG_ZIZE);
	return (0);
}

t_proc	*ft_mkproc()
{
	t_proc		*the_process;

	if (!(the_process = (t_proc*)malloc(sizeof(t_proc))))
		return (NULL);
	if (!(the_process.header = (t_header*)malloc(sizeof(t_header))))
	{
		free(the_process);
		return (NULL);
	}
	return (the_process);
}

t_list	*ft_add_process(t_list *processes)
{
	t_list	*new;
	t_proc	*process;

	if (!(process = mkproc()))
		return (NULL);
	if (!(new = (t_list*)ft_lstnew((void)process, (sizeof(t_proc)))))
		return (NULL);
	if (ft_empty_process(process))
		return (NULL);
	if (processes = NULL)
		return (new);
	else
		processes = ft_lstadd_end(&processes, new);
	return (processes);
}

t_vm	*ft_init_vm(t_vm *data)
{
	data->nb_players = 0;
	data->dump = -1;
	data->verbose = 0;
	data->cycles = 0;
	data->players_alive = 0;
	data->cycle_reduction = 0;
	data->processes = NULL;
	data->players = NULL;
	data->checks = 0;
	ft_bzero((void*)data.ram, MEM_SIZE);
	return (data);
}
