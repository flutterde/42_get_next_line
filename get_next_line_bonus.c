/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:26:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/22 15:09:58 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char **rest, int *rb, int fd)
{
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!tmp && *rb > 0)
	{
		*rb = read(fd, buff, BUFFER_SIZE);
		if (*rb < 0)
			break ;
		buff[*rb] = '\0';
		*rest = ft_strjoin(*rest, buff);
		tmp = ft_strchr(buff, '\n');
	}
	free(buff);
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX];
	char		*tmp;
	char		*tmp2;
	int			rb;

	rb = 1;
	line = NULL;
	if ((fd <= 2 && fd != 0) || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	tmp2 = read_line(&rest[fd], &rb, fd);
	tmp = ft_strchr(rest[fd], '\n');
	if (!tmp)
	{
		line = ft_strdup(rest[fd]);
		return (free(rest[fd]), rest[fd] = NULL, line);
	}
	else
	{
		line = _substr(rest[fd], tmp + 1);
		tmp2 = rest[fd];
		return (rest[fd] = ft_strdup(tmp + 1), free(tmp2), line);
	}
	return (NULL);
}
