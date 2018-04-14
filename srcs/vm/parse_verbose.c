/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verbose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:06:25 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/03 12:19:55 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


int	verbose_live(t_vm *data)
{
	if (data->verbose & 1)
		return (1);
	return (0);
}

int	verbose_cycle(t_vm *data)
{
	if (data->verbose & 2)
		return (1);
	return (0);
}
int	verbose_operations(t_vm *data)
{
	if (data->verbose & 4)
		return (1);
	return (0);
}

int	verbose_deaths(t_vm *data)
{
	if (data->verbose & 8)
		return (1);
	return (0);
}

int	verbose_pc(t_vm *data)
{
	if (data->verbose & 16)
		return (1);
	return (0);
}
