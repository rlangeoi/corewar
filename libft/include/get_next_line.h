/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:19:19 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:12:55 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 256

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct		s_file
{
	char			*buff;
	int				ind;
	int				fd;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
