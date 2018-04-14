/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:04:49 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/14 14:30:33 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
#include <stdio.h>

static void	ft_live(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("live\n");
	 
}

static void	ft_ld(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("ld\n");
	 
}

static void	ft_st(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("st\n");
	 
}

static void	ft_add(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("add\n");
	 
}

static void	ft_sub(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("sub\n");
	 
}

static void	ft_and(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("and\n");
	 
}

static void	ft_or(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("or\n");
	 
}

static void	ft_xor(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("xor\n");
	 
}

static void	ft_zjmp(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("zjmp\n");
	 
}

static void	ft_ldi(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("ldi\n");
	 
}

static void	ft_sti(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("sti\n");
	 
}

static void	ft_fork(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("fork\n");
	 
}

static void	ft_lld(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("lld\n");
	 
}

static void	ft_lldi(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("lldi\n");
	 
}

static void	ft_lfork(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("lfork\n");
	 
}

static void	ft_aff(t_vm *data, t_proc *proc)
{
	int	the_int;
	
	the_int = data->verbose;
	the_int = proc->pc;
	ft_printf("aff\n");
	 
}

void	ft_init_fake_instructions(t_vm *data)
{
	data->f[0] = ft_live;
	data->f[1] = ft_ld;
	data->f[2] = ft_st;
	data->f[3] = ft_add;
	data->f[4] = ft_sub;
	data->f[5] = ft_and;
	data->f[6] = ft_or;
	data->f[7] = ft_xor;
	data->f[8] = ft_zjmp;
	data->f[9] = ft_ldi;
	data->f[10] = ft_sti;
	data->f[11] = ft_fork;
	data->f[12] = ft_lld;
	data->f[13] = ft_lldi;
	data->f[14] = ft_lfork;
	data->f[15] = ft_aff;
}

void	ft_herald_debug(t_list *procs)
{
	header_t	*head;
	t_proc		*proc;

	while (procs)
	{
		proc = (t_proc*)procs->content;
		head = (header_t*)proc->header;
		printf("pc %d, player %d, num %d, name %s\n", proc->pc,
				proc->player, proc->num, head->prog_name);
		procs = procs->next;
	}
}

void	ft_vomit_data(t_vm *data)
{
	int i;

	ft_printf("nb_players = %hhu, verbose = %hhu, flags = %hhu, dump = %d\n",
			data->nb_players, data->verbose, data->flags, data->dump);
	i = -1;
	while (++i < 4)
	{
		ft_printf("Player #%d : %s\n", i + 1, data->players[i]);
	}
}

void	ft_something_something(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (data->ram[i] == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		if (i % 2 != 0)
			write(1, " ", 1);
	}
}

void	ft_print_headers(t_vm *data)
{
	t_list		*list;
	header_t	*head;

	list = data->headers;
	while (list != NULL)
	{
		if (list != NULL && list->content != NULL)
		{
			head = (header_t*)list->content;
			ft_printf("name %s, magic %d, comment %s, prog_size %d\n",
					head->prog_name, head->magic, head->comment,
					head->prog_size);
		}
		list = list->next;
	}
}
