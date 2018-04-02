/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/02 10:51:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VM_H
# define	VM_H

# include "op.h"
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define	REDUCED_CTD(data)		(CYCLE_TO_DIE - (CYCLE_DELTA * data->cycle_reductions))
# define	CYCLE_TO_CHECK(data)	(data->cycles % REDUCED_CTD)
# define	ERR_READ	"Can't read source file "
# define	ERR_MALLOC	"Couldn't allocate memory"
# define	ERR_DUMP	"Dump and verbose values cannot be negative"
# define	ERR_PNUM	"Invalid player number"
# define	ERR_HEADER	"Invalid header"
# define	NO_FLAG		0
# define	FLAG_AFF	1
# define	FLAG_CURSES	2
# define	FLAG_COLOR	4

typedef struct		s_proc
{
	char			reg[REG_SIZE * REG_NUMBER];
	char			pc[REG_SIZE];
	char			player;
	t_arg_type		arg_type[3];
	char			instruction;
	int				ocp;
	int				carry;
}					t_proc;

typedef struct		s_vm
{
	unsigned char	ram[MEM_SIZE];
	unsigned char	nb_players;
	unsigned char	verbose;
	unsigned char	flags;
	t_list			*processes;
	char			players[MAX_PLAYERS][CHAMP_MAX_SIZE];
	t_list			*headers;
	int				cycles;
	int				players_alive;
	int				cycle_reduction;
	int				dump;
	int				checks;
	void			(*f[16])(struct s_vm *, t_proc *);
}					t_vm;

void				ft_init_vm(t_vm *data);
t_list				*ft_add_process(t_list *processes);
void				ft_parse_arguments(int argc, char **argv, t_vm *data);
void				ft_parse_champs(t_vm *data);
int					ft_check_data(t_vm *data);
unsigned int		ft_check_endianness(t_vm *data);
unsigned int		switch_endianness(unsigned int bytes);
void				exit_error(char *error, char *file);
void				print_usage(void);

void				ft_vomit_data(t_vm *data);
void				ft_print_headers(t_vm *data);

#endif
