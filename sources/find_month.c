/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_month.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:07:28 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 15:22:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

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

static char	*browse_days(int month, int lmonth, int fd, int *fmonth, int *fday)
{
	char	*day;

	day = get_next_line(fd);
	if (!day)
		return (NULL);
	*fmonth = find_time(day, 5);
	*fday = find_time(day, 8);
	while ((*fmonth != month && *fmonth != lmonth)
		|| (*fmonth == month && *fday > 26)
		|| (*fmonth == lmonth && *fday > 27))
	{
		free(day);
		day = get_next_line(fd);
		if (!day)
			return (NULL);
		*fmonth = find_time(day, 5);
		*fday = find_time(day, 8);
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

static void	get_month(char **date, int month, int lastmonth, int fd)
{
	int	found_month;
	int	found_day;
	int	i;

	i = 0;
	found_month = find_time(date[i], 5);
	found_day = find_time(date[i], 8);
	while ((date[i] && found_month == month && found_day < 27)
		|| (date[i] && found_month == lastmonth && found_day > 26))
	{
		date[++i] = get_next_line(fd);
		if (!date[i])
			break ;
		found_month = find_time(date[i], 5);
		found_day = find_time(date[i], 8);
	}
	free(date[i]);
	date[i] = 0;
}

char	**parse_month(int month, int lastmonth, int fd)
{
	char	**date;

	date = ft_calloc(32, sizeof(char *));
	if (!date)
		return (NULL);
	*date = get_day(month, lastmonth, fd);
	if (!*date)
	{
		free_month(date);
		return (NULL);
	}
	get_month(date, month, lastmonth, fd);
	return (date);
}
