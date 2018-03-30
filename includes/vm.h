/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/30 18:16:08 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VM_H
# define	VM_H

# include "op.h"

# define	REDUCED_CTD(data)		(CYCLE_TO_DIE - (CYCLE_DELTA * data->cycle_reductions))
# define	CYCLE_TO_CHECK(data)	(data->cycles % REDUCED_CTD)

typedef struct	s_vm
{
	char		ram[MEM_SIZE];
	char		nb_players;
	char		verbose;
	t_list		*processes;
	t_list		*players;
	int			cycles;
	int			players_alive;
	int			cycle_reduction;
	int			dump;
	int			checks;
	void		(*f[16])(struct s_vm *, t_proc *);
}				t_vm;

typedef struct	s_proc
{
	char		reg[REG_SIZE * REG_NUMBER];
	char		pc[REG_SIZE];
	char		player;
	t_header	header;
	t_arg_type	arg_type[3];
	char		instruction;
	int			ocp;
	int			carry;
}				t_proc;

#endif
