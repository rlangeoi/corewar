/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:07:22 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/22 15:23:23 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	store_reg(t_vm *data, int address, int reg_val)
{
	while (address < 0)
		address = address + MEM_SIZE;
	MEMORY(address + 3) = reg_val;
	MEMORY(address + 2) = (reg_val >> 8);
	MEMORY(address + 1) = (reg_val >> 16);
	MEMORY(address + 0) = (reg_val >> 24);
}
