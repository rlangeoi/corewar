/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:27:42 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/06 17:51:46 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include "../../includes/vm.h"
#include "../../libft/include/libft.h"

int	main(int argc, char **argv)
{
	t_vm	data;

	if (argc > 1)
	{
		ft_init_vm(&data);
		ft_parse_arguments(argc, argv, &data);
		ft_check_data(&data);
		ft_vomit_data(&data);
		ft_parse_champs(&data);
		ft_print_headers(&data);
		ft_create_processes(&data);
		ft_copy_champs(&data, data.headers);
		ft_something_something(&data);
		ft_herald(&data, data.processes);
	}
}
