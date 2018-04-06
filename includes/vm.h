/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/06 19:10:42 by rlangeoi         ###   ########.fr       */
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
# define	ERR_HEADER	"Invalid header "
# define	ERR_SIZE	"Program size does not match header"
# define	ERR_UNKNOWN	"Unknown error happened. Exiting"
# define	NO_FLAG		0
# define	FLAG_AFF	1
# define	FLAG_CURSES	2
# define	FLAG_COLOR	4

typedef struct		s_proc
{
	char			reg[REG_SIZE * REG_NUMBER];
	char			player;
	char			num;
	int				param[3];
	t_arg_type		arg_type[3];
	char			instruction;
	int				pc;
	int				pc2;
	int				at_cycle;
	int				live_at_cycle;
	int				ocp;
	int				carry;
	int				live;
	header_t		*header;
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
	int				nb_proc;
	int				players_alive;
	int				cycle_reduction;
	int				dump;
	int				checks;
	void			(*f[16])(struct s_vm *, t_proc *);
}					t_vm;

void				ft_init_vm(t_vm *data);
t_list				*ft_add_process(t_list *processes, int pnum);
void				ft_create_processes(t_vm *data);
void				ft_find_header_pnum(t_vm *data, int pnum);
void				ft_get_header_number(t_vm *data, int players, t_proc *processes);
t_proc				*ft_get_proc_pnum(t_vm *data, int pnum);
void				ft_parse_arguments(int argc, char **argv, t_vm *data);
void				ft_parse_champs(t_vm *data);
void				ft_copy_champs(t_vm *data, t_list *listheaders);
int					ft_check_data(t_vm *data);
void				ft_herald(t_vm *data, t_list *lstproc);
unsigned int		ft_check_endianness(t_vm *data);
unsigned int		switch_endianness(unsigned int bytes);
void				exit_error(char *error, char *file);
void				print_usage(void);

void				ft_vomit_data(t_vm *data);
void				ft_print_headers(t_vm *data);
void				ft_something_something(t_vm *data);
void				ft_herald_debug(t_vm *data, t_list *procs);

#endif
