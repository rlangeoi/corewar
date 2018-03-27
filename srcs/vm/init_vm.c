/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:41:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/27 17:39:58 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_empty_process(t_proc the_process)
{
	the_process->player = 0;
	the_process->instruction = 0;
	the_process->ocp = 0;
	return (0);
}

t_process	*ft_mkproc()
{
	t_proc		*the_process;
	t_header	*the_header;

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

int	ft_init_vm(t_vm *data)
{
	data->nb_players = 0;
	data->flags = 0;
	data->cycles = 0;
	data->players_alive = 0;
	data->cycle_reduction = 0;
	return (ft_memset((void)(data->ram), (char)0, MEM_SIZE));
}
