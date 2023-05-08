/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:21:37 by mabaron-          #+#    #+#             */
/*   Updated: 2023/01/06 14:34:50 by mabaron-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cleanup(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i])
		rest = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	else
	{
		free (stash);
		return (NULL);
	}
	i++;
	if (!rest)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

static char	*ft_extract(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		line[++i] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*ft_read_and_stash(int fd, char *stash)
{
	char	*nstr;
	char	tmp[BUFFER_SIZE + 1];
	int		byte;

	byte = 1;
	nstr = NULL;
	while (!ft_strchr(stash, '\n') && byte != 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == -1)
		{
			if (nstr)
				free (nstr);
			if (stash && stash != nstr)
				free (stash);
			return (NULL);
		}
		tmp[byte] = '\0';
		nstr = ft_strjoin_gnl(stash, tmp);
		if (stash)
			free(stash);
		stash = nstr;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_read_and_stash(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_extract(buff[fd]);
	buff[fd] = ft_cleanup(buff[fd]);
	return (line);
}
