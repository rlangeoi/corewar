/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:04:49 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/06 19:57:51 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
#include <stdio.h>

void	ft_herald_debug(t_vm *data, t_list *procs)
{
	header_t	*head;
	t_proc		*proc;

	while (procs)
	{
		proc = (t_proc*)procs->content;
		head = (header_t*)proc->header;
		printf("pc %d, player %d, num %d, name %s\n", proc->pc,
				proc->player, proc->num, head->prog_name);
		procs = procs->next;
	}
}

void	ft_vomit_data(t_vm *data)
{
	int i;

	ft_printf("nb_players = %hhu, verbose = %hhu, flags = %hhu, dump = %d\n",
			data->nb_players, data->verbose, data->flags, data->dump);
	i = -1;
	while (++i < 4)
	{
		ft_printf("Player #%d : %s\n", i + 1, data->players[i]);
	}
}

void	ft_something_something(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (data->ram[i] == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		if (i % 2 != 0)
			write(1, " ", 1);
	}
}

void	ft_print_headers(t_vm *data)
{
	t_list		*list;
	header_t	*head;

	list = data->headers;
	while (list != NULL)
	{
		if (list != NULL && list->content != NULL)
		{
			head = (header_t*)list->content;
			ft_printf("name %s, magic %d, comment %s, prog_size %d\n",
					head->prog_name, head->magic, head->comment,
					head->prog_size);
		}
		list = list->next;
	}
}
