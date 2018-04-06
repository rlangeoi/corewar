/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:25:14 by                   #+#    #+#             */
/*   Updated: 2018/04/06 16:33:06 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_check_data(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (data->players[i][0] != '\0')
			(data->nb_players)++;
	}
	if (data->nb_players == 0)
		exit_error("No Players", NULL);
	if (data->dump < -1 || (char)data->verbose < 0)
		exit_error(ERR_DUMP, NULL);
	return (0);
}
