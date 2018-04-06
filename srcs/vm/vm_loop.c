/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:25:27 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/06 20:09:37 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_process(t_vm *data, t_proc *proc)
{

}

void	ft_vm_loop(t_vm *data, t_list *processes)
{
	t_proc	*process;

	while (data->cycles <= vm_dump && processes)
	{
		processes = data->processes;
		while (processes)
		{
			process = (t_proc*)processes->content;
			ft_process(data, process);
		}
	}
}
