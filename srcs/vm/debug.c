/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:04:49 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/01 16:00:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_vomit_data(t_vm *data)
{
	int i;

	ft_printf("nb_players = %hhu, verbose = %hhu, flags = %hhu, dump = %d\n", data->nb_players, data->verbose, data->flags, data->dump);
	i = -1;
	while (++i < 4)
	{
		ft_printf("Player #%d : %s\n", i + 1, data->players[i]);
	}
}
