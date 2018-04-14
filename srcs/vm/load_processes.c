/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:11:36 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/14 16:42:32 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_herald(t_list *lstproc)
{
	t_proc		*process;
	header_t	*head;

	ft_printf("Introducing contestants...\n");
	while (lstproc)
	{
		process = lstproc->content;
		head = process->header;
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				process->num, head->prog_size, head->prog_name, head->comment);
		lstproc = lstproc->next;
	}
}

void	ft_copy_champs(t_vm *data, t_list *listheaders)
{
	int			i;
	int			ram_index;
	header_t	*header;

	i = MAX_PLAYERS;
	ram_index = 0;
	while (--i >= 0)
	{
		if (data->players[i][0] != 0)
		{
			if (listheaders == NULL)
				exit_error(ERR_UNKNOWN, NULL);
			header = (header_t*)listheaders->content;
			ft_memcpy(&data->ram[ram_index], data->players[i],
					(size_t)header->prog_size);
			listheaders = listheaders->next;
			ram_index = ((ram_index + (MEM_SIZE / data->nb_players))
					% MEM_SIZE);
		}
	}
	data->nb_proc = data->nb_players;
}
