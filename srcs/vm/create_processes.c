/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:08:30 by                   #+#    #+#             */
/*   Updated: 2018/04/05 18:41:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_create_processes(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (data->players[i][0] != 0)
		{
			if (!(data->processes = ft_add_process(data->processes)))
				exit_error(ERR_MALLOC, NULL);
			else
		}
	}
}
