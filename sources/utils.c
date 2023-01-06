/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/06 08:21:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
#include <time.h>

/* TELLS WHAT THE MONTH IS */
char	*month_is(char *src)
{
	char	*dest;
	int		i = 0;
	int		j = 5;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

/* TELLS WHAT THE DAY IS */
char	*day_is(char *src)
{
	char	*dest;
	int		i = 0;
	int		j = 8;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

/* CLEAR DATE */
void	free_date(char **date)
{
	int	i = 0;

	while (date[i])
		free(date[i++]);
	free(date);
}

/* CALCULATES THE TIME LEFT */
void	ccl_timeleft(int *ttlog)
{
	if (ttlog[0] > 0)
	{
		ttlog[0] = 60 - ttlog[0];
		ttlog[1]++;
	}
	if (ttlog[1] > 0)
	{
		ttlog[1] = 60 - ttlog[1];
		ttlog[2]++;
	}
	ttlog[2] = 140 - ttlog[2];
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}

/* SUBSTR FOR PARSING THE LOGTIME */
char	*ft_substr(char *str, int len)
{
	char	*dest;
	int		i = 0;

	dest = malloc((len + 2) * sizeof(char));
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	free(str);
	dest[i++] = '"';
	dest[i] = 0;
	return (dest);
}
