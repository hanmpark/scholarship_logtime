/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:20:08 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:19:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"

static int	ft_is_nl(char *str)
{
	int		times;

	times = 0;
	if (!str)
		return (times);
	while (*str)
	{
		if (*str == '\n')
			times++;
		str++;
	}
	return (times);
}

static char	*ft_read(int fd, char *stash, char *get_line)
{
	char	*buffer;
	ssize_t	check;

	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (0);
	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE && !ft_is_nl(stash))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			ft_freeall(buffer, get_line, stash);
			return (0);
		}
		buffer[check] = 0;
		stash = ft_bufferjoin(stash, buffer);
	}
	free(buffer);
	get_line = ft_bufferjoin(get_line, stash);
	free(stash);
	return (get_line);
}

static char	*ft_checktrim(char *not_trimmed_line)
{
	char	*stash;
	int		i;

	stash = 0;
	i = 0;
	if (ft_is_nl(not_trimmed_line) == 1)
	{
		while (not_trimmed_line[i + 1])
			i++;
		if (not_trimmed_line[i] != '\n')
			stash = ft_linetrim(not_trimmed_line);
	}
	if (ft_is_nl(not_trimmed_line) > 1)
		stash = ft_linetrim(not_trimmed_line);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = calloc(1, sizeof(char));
	if (!line)
		return (0);
	line = ft_read(fd, stash[fd], line);
	if (!line)
	{
		stash[fd] = 0;
		return (0);
	}
	if (!*line)
	{
		free(line);
		return (0);
	}
	stash[fd] = ft_checktrim(line);
	return (line);
}
