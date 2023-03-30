/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_month.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:07:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/31 00:20:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"
#include "parse.h"

static int	find_time(char *src, int monthorday)
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
#include <stdio.h>
static char	*browse_days(int month, int lmonth, int fd, int *fmonth, int *fday)
{
	char	*day;

	day = get_next_line(fd);
	if (!day)
		return (NULL);
	*fmonth = find_time(day, 6);
	*fday = find_time(day, 9);
	while (*fmonth != month && *fmonth != lmonth)
	{
		free(day);
		day = get_next_line(fd);
		if (!day)
			return (NULL);
		*fmonth = find_time(day, 6);
		*fday = find_time(day, 9);
	}
	if (*fmonth == lmonth && *fday < 27)
	{
		free(day);
		return (NULL);
	}
	while ((*fmonth == month && *fday > 26))
	{
		free(day);
		day = get_next_line(fd);
		if (!day)
			return (NULL);
		*fmonth = find_time(day, 6);
		*fday = find_time(day, 9);
	}
	return (day);
}

static char	*get_day(int month, int lastmonth, int fd)
{
	int		found_month;
	int		found_day;
	char	*day;

	day = browse_days(month, lastmonth, fd, &found_month, &found_day);
	if (!day)
		return (NULL);
	if ((found_month != lastmonth && found_month != month)
		|| (found_month == lastmonth && found_day < 27))
	{
		free(day);
		return (NULL);
	}
	return (day);
}

static void	get_month_dates(char **date, int month, int lastmonth, int fd)
{
	int	found_month;
	int	found_day;
	int	i;

	i = 0;
	found_month = find_time(date[i], 6);
	found_day = find_time(date[i], 9);
	while ((date[i] && found_month == month && found_day < 27)
		|| (date[i] && found_month == lastmonth && found_day > 26))
	{
		date[++i] = get_next_line(fd);
		if (!date[i])
			break ;
		found_month = find_time(date[i], 6);
		found_day = find_time(date[i], 9);
	}
	free(date[i]);
	date[i] = 0;
}

char	**parse_month(int month, int lastmonth, int fd)
{
	char	**date;

	date = calloc(32, sizeof(char *));
	if (!date)
		return (NULL);
	*date = get_day(month, lastmonth, fd);
	if (!*date)
	{
		free_month(date);
		return (NULL);
	}
	get_month_dates(date, month, lastmonth, fd);
	return (date);
}

void	set_dates(t_data *data, int month, int last_month)
{
	int	fd;

	fd = open("dates.txt", O_RDONLY);
	data->chosen = parse_month(month, last_month, fd);
	close(fd);
	month = last_month;
	last_month = month - 1;
	if (month == 1)
		last_month = 12;
	fd = open("dates.txt", O_RDONLY);
	data->bonus = parse_month(month, last_month, fd);
	close(fd);
}
