/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:40:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/27 17:52:24 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_arguments(int argc, char **argv, t_vm *data)
{
	int	i;

	i = 0;
	while (++i < 4 && data->nb_players <= 4)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
			ft_parse_dump(av[i + 1]);
		else if (!(ft_strncmp(argv[i], "-v")))
			ft_parse_verbose(av[i + 1]);
		else if (
	}
}
