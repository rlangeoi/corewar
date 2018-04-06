/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:08:30 by                   #+#    #+#             */
/*   Updated: 2018/04/06 18:20:40 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

t_proc	*ft_get_proc_pnum(t_vm *data, int pnum)
{
	t_proc	*process;
	t_list	*list;
	
	list = data->processes;
	if (list)
		process = (t_proc*)list->content;
	if (process)
	{
		while (process->num != pnum)
		{
			if (list)
				list = list->next;
			if (list)
				process = (t_proc*)list->content;
			if (!(process))
				return (NULL);
		}
		return (process);
	}
	return (NULL);
}

void	ft_get_header_number(t_vm *data, int players, t_proc *process)
{
	t_list	*list;

	list = data->headers;
	if (process != NULL)
		process->player = (char)players;
	list = ft_lst_at(list, data->nb_players - (players));
	if (list != NULL)
		process->header = (header_t*)list->content;
	process->pc = (((MEM_SIZE / data->nb_players) * (players - 1)) % MEM_SIZE);
}

void	ft_find_header_pnum(t_vm *data, int pnum)
{
	int players;
	int	i;

	i = -1;
	players = 0;
	while (++i < MAX_PLAYERS && i <= pnum)
	{
		if (data->players[i][0] != 0)
			players++;
		if (i == pnum)
			ft_get_header_number(data, players, (t_proc*)data->processes->content);
	}
}

void	ft_create_processes(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (data->players[i][0] != 0)
		{
			if (!(data->processes = ft_add_process(data->processes, i + 1)))
				exit_error(ERR_MALLOC, NULL);
			else
				ft_find_header_pnum(data, i);
		}
	}
}
