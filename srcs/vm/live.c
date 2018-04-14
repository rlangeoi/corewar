/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 09:27:20 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 14:53:22 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*get_player(t_vm *data, int nb_champ)
{
	t_list		*champs;
	t_proc	*process;

	champs = data->champions;
	while (champs)
	{
		process = champs->content;
		if (nb_champ == process->id_champ)
		{
			process->nb_live++;
			return (process->header.prog_name);
		}
		champs = champs->next;
	}
	return (NULL);
}

void	live(t_vm *data, t_proc *process)
{
	char	*player;

	if (verbose_operations(data))
		ft_printf("P% 5d | live %d\n", ID, PARAM(0));
	process->cycles_wo_live = 0;
	data->live++;
	player = get_player(data, PARAM(0));
	if (player)
	{
		data->last_live = PARAM(0);
		if (verbose_live(data))
			ft_printf("Player %d (%s) is said to be alive\n", ft_abs(PARAM(0)), player);
	}
	advance_pc(data, process);
}
