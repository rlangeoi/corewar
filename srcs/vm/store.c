/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:07:22 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/20 14:18:53 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
/*
void	ft_graphic_handle(t_vm *data, int adress)
{
	int		idx;

	idx = 0;
	while (idx < 4)
	{
		if (data->mem_color[adress + idx] >= 0)
			attron(COLOR_PAIR(data->mem_color[(adress + idx) % MEM_SIZE]));
		else
			attron(COLOR_PAIR(5));
		mvwprintw(stdscr, ((adress + idx) % MEM_SIZE) / 64 + 2,
			((adress + idx) % MEM_SIZE) % 64 * 3 + 3, "%.2x ",
			data->ram[(adress + idx) % MEM_SIZE]);
		if (data->mem_color[(adress + idx) % MEM_SIZE] >= 0)
			attroff(COLOR_PAIR(data->mem_color[(adress + idx) % MEM_SIZE]));
		else
			attroff(COLOR_PAIR(5));
		idx++;
	}
}
*/
void	store_reg(t_vm *data, int address, int reg_val)
{
	//reg_val--;
	while (address < 0)
		address = address + MEM_SIZE;
	MEMORY(address + 3) = reg_val;
	MEMORY(address + 2) = (reg_val >> 8);
	MEMORY(address + 1) = (reg_val >> 16);
	MEMORY(address + 0) = (reg_val >> 24);
}
