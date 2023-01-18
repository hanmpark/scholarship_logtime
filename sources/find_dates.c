/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:07:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/18 15:54:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static int	find_monthorday(char *src, int monthorday)
{
	char	dest[3];
	int		res;
	int		i;

	i = 0;
	while (i < 2)
		dest[i++] = src[monthorday++];
	dest[i] = 0;
	res = atoi(dest);
	return (res);
}

static char	*get_day(int month, int lastmonth, int fd)
{
	char	*date;
	int		found_month;
	int		found_day;

	date = get_next_line(fd);
	if (!date)
		return (NULL);
	found_month = find_monthorday(date, 5);
	found_day = find_monthorday(date, 8);
	while ((found_month != month && found_month != lastmonth)
		|| (found_month == month && found_day > 26))
	{
		free(date);
		date = get_next_line(fd);
		if (!date)
			return (NULL);
		found_month = find_monthorday(date, 5);
		found_day = find_monthorday(date, 8);
	}
	if ((found_month != lastmonth && found_month != month)
		|| (found_month == lastmonth && found_day < 27))
		return (NULL);
	return (date);
}

static void	get_month(char **date, int month, int lastmonth, int fd)
{
	int	found_month;
	int	found_day;
	int	i;

	i = 0;
	found_month = find_monthorday(date[i], 5);
	found_day = find_monthorday(date[i], 8);
	while ((date[i] && found_month == month && found_day < 27)
		|| (date[i] && found_month == lastmonth && found_day > 26))
	{
		date[++i] = get_next_line(fd);
		if (!date[i])
			break ;
		found_month = find_monthorday(date[i], 5);
		found_day = find_monthorday(date[i], 8);
	}
	date[i] = 0;
}

char	**parse_month(int month, int lastmonth, int fd)
{
	char	**date;

	date = ft_calloc(32, sizeof(char *));
	if (!date)
		return (NULL);
	date[0] = get_day(month, lastmonth, fd);
	if (!date[0])
	{
		free(date);
		return (NULL);
	}
	get_month(date, month, lastmonth, fd);
	return (date);
}
