/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:25:27 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/08 19:56:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_vm_loop(t_vm *data, t_list *processes)
{
	t_proc	*process;

	while ((data->cycles <= data->dump || data->dump < 0) && processes)
	{
		processes = data->processes;
		while (processes)
		{
			ft_printf("Wesh\n");
			process = (t_proc*)processes->content;
			ft_process(data, process);
			processes = processes->next;
		}
	}
}
