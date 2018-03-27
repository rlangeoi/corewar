/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/27 15:50:53 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VM_H
# define	VM_H

# include "op.h"

# define	REDUCED_CTD		(CYCLE_TO_DIE - (CYCLE_DELTA * data->cycle_reductions))
# define	CYCLE_TO_CHECK	(data->cycles % REDUCED_CTD)

typedef struct	s_vm
{
	char	ram[MEM_SIZE];
	char	nb_players;
	char	flags;
	t_list	*processes;
	t_list	*players;
	int		cycles;
	int		players_alive;
	int		cycle_reduction;
}

#endif
