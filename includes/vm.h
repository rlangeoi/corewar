/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/27 15:40:43 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VM_H
# define	VM_H

typedef struct	s_vm
{
	char	ram[MEM_SIZE];
	char	nb_players;
	char	flags;
	t_list	*processes;
	t_list	*players;
	int		cycles;
	int		players_alive;
}

#endif
