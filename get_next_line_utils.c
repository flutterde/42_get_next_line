/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:27:16 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/20 23:38:42 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*nstr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!len)
		return (NULL);
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		nstr[j++] = ((char *)s1)[i++];
	i = 0;
	while (s2[i])
		nstr[j++] = ((char *)s2)[i++];
	return (nstr[j] = '\0', free(s1), nstr);
}

char	*ft_strdup(char *s1)
{
	char	*ns;
	size_t	i;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	if (!l)
		return (NULL);
	ns = malloc(l + 1);
	if (!ns)
		return (NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	ns[i] = '\0';
	return (ns);
}

char	*_substr(char *begin, char *end)
{
	int		i;
	int		l;
	char	*nstr;
	char	*xbegin;
	char	*xend;

	i = -1;
	xbegin = begin;
	xend = end;
	if (!begin || !end)
		return (NULL);
	l = 0;
	while (xbegin++ < xend)
		l++;
	nstr = malloc(l + 1);
	if (!l)
		return (NULL);
	while (++i < l)
		nstr[i] = begin[i];
	nstr[i] = '\0';
	return (nstr);
}
