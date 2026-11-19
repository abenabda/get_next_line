/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:39:03 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/19 15:19:47 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	read_size = 1;
	while (!ft_strchr(stash, '\n') && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (free(buffer), free(stash), NULL);
		buffer[read_size] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*trim_stash(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	line = ft_strdup(&stash[i + 1]);
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = trim_stash(stash);
	return (line);
}
