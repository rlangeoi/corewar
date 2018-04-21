/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:25:27 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/21 16:43:20 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

header_t	*get_header(t_vm *data, t_list *headers, int player)
{
	int			i;
	int			j;
	header_t	*ret;

	i = -1;
	j = 0;
	while (++i < MAX_PLAYERS && i < player)
	{
		if (data->pnums[i])
			j++;
	}
	headers = ft_lst_at(headers, j);
	ret = ((header_t*)(headers->content));
	return (ret);
}

void		ft_herald_winner(t_vm *data)
{
	t_list		*headers;
	header_t	*head;

	headers = data->headers;
	if (data->cycles < data->dump || data->dump < 0)
	{
		head = get_header(data, headers, ABS(data->last_live));
		ft_printf("Contestant %d, \"%s\", has won !\n", ABS(data->last_live), head->prog_name);
	}
}

static void	ft_check_alive(t_vm	*data)
{
	t_proc	*process;
	t_list	*cur;
	int		i;

	i = 0;
	cur = data->processes;
	while (cur)
	{
		i++;
		process = (t_proc*)cur->content;
		cur = cur->next;
		if (process->live_at_cycle >= CYCLE_TO_DIE -
				(CYCLE_DELTA * data->cycle_reduction))
		{
			if (data->verbose)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
						process->id, process->live_at_cycle, REDUCED_CTD(data));
			ft_lstrm_at(&(data->processes), i--);
		}
	}
}

static void	ft_cycles(t_vm *data)
{
		data->cycles++;
		if (data->cycle_check <= data->cycles - 1)
		{
			ft_check_alive(data);
			data->checks++;
			if (data->live >= NBR_LIVE || data->checks >= MAX_CHECKS)
			{
				data->cycle_reduction++;
				data->cycle_check += CYCLE_TO_DIE -
					(CYCLE_DELTA * data->cycle_reduction);
				if (data->verbose)
					ft_printf("Cycle to die is now %d\n",
							REDUCED_CTD(data));
				data->checks = 0;
			}
			data->live = 0;
		}
}

void		ft_vm_loop(t_vm *data, t_list *processes)
{
	t_proc	*process;

	while ((data->cycles <= data->dump || data->dump < 0) && processes)
	{
		if (data->verbose)
			ft_printf("It is now cycle %d\n",data->cycles);
		while (processes)
		{
			process = (t_proc*)processes->content;
			process->live_at_cycle++;
			ft_process(data, process);
			processes = processes->next;
		}
		ft_cycles(data);
		processes = data->processes;
	}
	if (processes)
		ft_dump_data(data);
}
