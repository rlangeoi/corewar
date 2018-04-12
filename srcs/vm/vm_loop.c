/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:25:27 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/12 12:14:47 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	ft_check_alive(t_vm *data, t_list *processes)
{
	while (processes)
	{
		if (!ft_is_alive(processes))
		{

		}
	}	
}

static void	ft_cycles(t_vm *data)
{
		data->cycles++;
		if (CYCLE_TO_CHECK(data) == 0)
		{
			ft_printf("cycle_to_check 0\n");
			ft_check_alive(data, data->processes);
			data->checks++;
			if (data->live >= NBR_LIVE || data->checks >= MAX_CHECKS)
			{
				data->cycle_reduction++;
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
			ft_printf("It is now cycle%d\n",data->cycles);
		while (processes)
		{
			ft_printf("Wesh\n");
			process = (t_proc*)processes->content;
			ft_process(data, process);
			processes = processes->next;
		}
		ft_cycles(data);
	}
	//dump + debug
}
