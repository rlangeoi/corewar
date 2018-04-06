/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:32:26 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/06 19:52:31 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	ft_parse_instructions(t_list *lst, char *player, int fd)
{
	int			r;
	int			psize;
	header_t	*header;

	header = (header_t*)lst->content;
	psize = (int)header->prog_size;
	if ((r = read(fd, player, psize)) == -1)
		exit_error(ERR_READ, NULL);
	ft_printf("r %d, psize %d\n", r, psize);
	if (r != psize)
		exit_error(ERR_SIZE, NULL);
}

static void	ft_parse_headers(t_vm *data, int fd, int pnum)
{
	header_t	*header;
	t_list		*new;
	int			i;

	if (!(header = (header_t*)malloc(sizeof(header_t))))
		exit_error(ERR_MALLOC, NULL);
	if ((i = read(fd, (void *)(header), sizeof(header_t))) == -1)
		exit_error(ERR_READ, NULL);
	if (i != sizeof(header_t))
		exit_error(ERR_HEADER, header->prog_name);
	header->magic = switch_endianness(header->magic);
	header->prog_size = switch_endianness(header->prog_size);
	ft_printf("i:%d, sizeof:%d, magic:%d, corewarmagic:%d\n", i,
			sizeof(header_t), header->magic, COREWAR_EXEC_MAGIC);
	if (header->prog_size > CHAMP_MAX_SIZE)
		exit_error("Champ too big in ", data->players[pnum]);
	if (!(new = ft_lstnew(((void*)header), sizeof(header_t))))
		exit_error(ERR_MALLOC, NULL);
	ft_lstadd(&(data->headers), new);
}

void		ft_parse_champs(t_vm *data)
{
	int	i;
	int fd;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		ft_printf("i%d\n", i);
		if (data->players[i][0])
		{
			if ((fd = open(data->players[i], O_RDONLY)) != -1)
			{
				ft_parse_headers(data, fd, i);
				ft_parse_instructions(data->headers, data->players[i], fd);
				if ((fd = close(fd)) == -1)
					exit_error(ERR_READ, NULL);
			}
			else
				exit_error(ERR_READ, NULL);
		}
	}
	ft_printf("byebye\n");
}
