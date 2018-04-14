/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:10:12 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/14 17:11:51 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	aff(t_vm *data, t_proc *process)
{
	int	character;

	if (is_reg(process, 0) && data->aff)
	{
		character = REG(0) % 256;
		ft_printf("Aff : %c\n", (char)character);
		process->carry = character ? 0 : 1;
	}
	advance_pc(data, process);
}
