/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 13:48:14 by lgosse            #+#    #+#             */
/*   Updated: 2018/04/14 18:02:57 by rlangeoi         ###   ########.fr       */
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
void	store_reg(t_vm *data, int adress, int reg_val)
{
	MEMORY(adress + 3) = reg_val;
	MEMORY(adress + 2) = (reg_val >> 8);
	MEMORY(adress + 1) = (reg_val >> 16);
	MEMORY(adress + 0) = (reg_val >> 24);
}
