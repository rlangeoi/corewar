/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:40:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/03/27 18:03:10 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_dump(char *arg)
{
	if (ft_isdigitstr(arg))
		return (ft_atoi(arg));
	else
		print_usage();
	return (-1);
}

int	ft_parse_arguments(int argc, char **argv, t_vm *data)
{
	int	i;
	int	pnum;

	i = 0;
	while (++i < 4 && data->nb_players <= 4)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
			data->dump = ft_parse_dump(argv[i + 1]);
		else if (!(ft_strncmp(argv[i], "-n")))
			ft_parse_pnum(argv[i + 1], &pnum);
		else if (
	}
}
