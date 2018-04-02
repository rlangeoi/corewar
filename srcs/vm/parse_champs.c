/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:32:26 by                   #+#    #+#             */
/*   Updated: 2018/04/02 11:54:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_parse_instructions(t_vm *data, int fd, int pnum, unsigned int psize)
{
	int 		r;
	t_list		*list;
	header_t	*header;

	if ((r = read(fd, data->players[pnum],
}

void	ft_parse_headers(t_vm *data, int fd)
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
	ft_printf("i:%d\n, sizeof:%d\n, magic:%d\n, corewarmagic:%d\n, sizeof:%d\n", i, sizeof(header_t), header->magic, COREWAR_EXEC_MAGIC, sizeof(header));
	if (!(new = ft_lstnew(((header_t*)header), sizeof(header_t))))
		exit_error(ERR_MALLOC, NULL);
	ft_lstadd_end(&(data->headers), new);
}

void	ft_parse_champs(t_vm *data)
{
	int	i;
	int fd;
	int psize;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (data->players[i][0])
			if ((fd = open(data->players[i], O_RDONLY)) != -1)
			{
				ft_parse_headers(data, fd);
				ft_parse_instructions(data, fd, i);
				if ((fd = close(fd)) == -1)
					exit_error(ERR_READ, NULL);
			}
	}
}
