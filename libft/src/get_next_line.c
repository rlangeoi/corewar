/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:12:31 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/14 22:14:08 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*find_fd(t_file *file, int fd)
{
	t_file *new;

	if (file != NULL)
	{
		while (file->next != NULL && file->fd != fd)
			file = file->next;
	}
	if (file == NULL || (file->next == NULL && file->fd != fd))
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		new->fd = fd;
		new->ind = 0;
		new->next = NULL;
		new->buff = NULL;
		if (file != NULL)
			file->next = new;
		return (new);
	}
	else
		return (file);
}

static int		fill_buff(t_file *file, int fd, char **line)
{
	int ret;

	if (file->buff != NULL)
		free(file->buff);
	if (!(file->buff = ft_strnew((size_t)BUFF_SIZE)))
		return (-1);
	ret = read(fd, file->buff, BUFF_SIZE);
	if ((ret == 0 && file->ind > 0) || ret == -1)
	{
		if (*line != NULL && line[0][0])
			return (1);
		return (ret);
	}
	else
		file->ind = 0;
	return (2);
}

static size_t	gnl_temp(char **temp, char **line)
{
	size_t len;

	*temp = ft_strdup(*line);
	len = ft_strlen(*line);
	free(*line);
	return (len);
}

static int		treat_buff(t_file *file, char **line)
{
	int		s;
	size_t	len;
	char	*temp;

	s = file->ind;
	len = 0;
	temp = NULL;
	while (file->ind < BUFF_SIZE && file->buff[(file->ind)] != '\n')
		file->ind++;
	if (*line)
		len = gnl_temp(&temp, line);
	*line = ft_strnew(len + (file->ind) - s);
	if (temp != NULL)
		ft_strncpy(*line, temp, len);
	free(temp);
	ft_strncpy((&line[0][len]), &file->buff[s], (file->ind - s));
	line[0][((file->ind - s) + len)] = '\0';
	if (file->ind < BUFF_SIZE)
	{
		file->ind++;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_file	*alst;
	t_file			*file;

	if (fd < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	ret = 0;
	*line = NULL;
	file = find_fd(alst, fd);
	if (alst == NULL)
		alst = file;
	if (alst == NULL)
		return (-1);
	while (ret != 1)
	{
		if (file->ind == 0 || file->ind == BUFF_SIZE)
		{
			ret = fill_buff(file, fd, line);
			if (ret < 2)
				return (ret);
		}
		ret = treat_buff(file, line);
	}
	return (ret);
}
