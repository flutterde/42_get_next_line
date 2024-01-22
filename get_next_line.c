/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:26:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/21 12:36:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*__calloc(size_t len)
{
	char	*data;
	size_t	i;

	if (len <= 0)
		return (NULL);
	data = malloc(len);
	if (!data)
		return (NULL);
	i = 0;
	while (i < len)
		data[i++] = '\0';
	return (data);
}

char	*read_line(char **rest, int *rb, int fd)
{
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = NULL;
	while (!tmp && *rb > 0)
	{
		buff = __calloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		*rb = read(fd, buff, BUFFER_SIZE);
		*rest = ft_strjoin(*rest, buff);
		tmp = ft_strchr(buff, '\n');
		free(buff);
	}
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	char		*tmp;
	char		*tmp2;
	int			rb;

	rb = 1;
	line = NULL;
	if ((fd <= 2 && fd != 0) || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(rest), rest = NULL, NULL);
	tmp2 = read_line(&rest, &rb, fd);
	tmp = ft_strchr(rest, '\n');
	if (!tmp)
		return (line = ft_strdup(rest), free(rest), rest = NULL, line);
	else
	{
		line = _substr(rest, tmp + 1);
		return (tmp2 = rest, rest = ft_strdup(tmp + 1), free(tmp2), line);
	}
	return (NULL);
}
