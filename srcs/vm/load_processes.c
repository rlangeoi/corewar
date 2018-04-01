/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:11:36 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/01 18:32:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_load_champs(t_vm *data, int i)

void	ft_load_processes(t_vm *data)
{
	t_list	*temp;
	int		player;
	int		i;
	int		j;
	t_list	*process;
	
	//memset color;
	i = -1;
	process = data->processes;
	while (process && process->content && process->content->player <
			data->nb_players)
	{
		player = process->content->player;
		j = -1;
		while (process->content->player == player)
		{
			i = i % MEM_SIZE;
			data->ram[i] = 
		}
		process = process->next;

	}
}
