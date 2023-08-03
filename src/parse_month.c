/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_month.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:41:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/03 21:47:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"
#include "get_time.h"

static char	*find_potential_ref_date(int month, int last_month, int fd)
{
	char	*date;

	date = get_next_line(fd);
	if (!date)
		return (NULL);
	while (find_time(date, TXT_MONTH) != month && find_time(date, TXT_MONTH) != last_month)
	{
		free(date);
		date = get_next_line(fd);
		if (!date)
			return (NULL);
	}
	return (date);
}

static char	*get_reference_date(int month, int last_month, int fd)
{
	char	*date;

	date = find_potential_ref_date(month, last_month, fd);
	if (!date)
		return (NULL);
	while ((find_time(date, TXT_MONTH) == month && find_time(date, TXT_DAY) > 26))
	{
		free(date);
		date = get_next_line(fd);
		if (!date)
			return (NULL);
	}
	if (find_time(date, TXT_MONTH) == last_month && find_time(date, TXT_DAY) < 27)
	{
		free(date);
		return (NULL);
	}
	return (date);
}

static bool	is_correct_date(char *date, int month, int last_month)
{
	return ((date && find_time(date, TXT_MONTH) == month && find_time(date, TXT_DAY) < 27)
		|| (date && find_time(date, TXT_MONTH) == last_month && find_time(date, TXT_DAY) > 26));
}

static char	**find_month_dates(int month, int last_month, int fd)
{
	char	**month_dates;
	int		i;

	month_dates = calloc(32, sizeof(char *));
	if (!month_dates)
		return (NULL);
	i = 0;
	month_dates[i] = get_reference_date(month, last_month, fd);
	if (!month_dates[i])
	{
		free_array(month_dates);
		return (NULL);
	}
	while (is_correct_date(month_dates[i], month, last_month))
	{
		month_dates[++i] = get_next_line(fd);
		if (!month_dates[i])
			break ;
	}
	free(month_dates[i]);
	month_dates[i] = 0;
	return (month_dates);
}

static char	**get_dates(const char *file, int month, int last_month)
{
	char	**month_dates;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	month_dates = find_month_dates(month, last_month, fd);
	close(fd);
	return (month_dates);
}

void	set_dates(t_data *data)
{
	int	month;
	int	last_month;

	month = data->month;
	last_month = data->last_month;
	data->chosen = get_dates("dates.txt", month, last_month);
	data->holidays = get_dates("holidays.txt", month, last_month);
	month = last_month;
	last_month = month - 1;
	if (month == 1)
		last_month = 12;
	data->bonus = get_dates("dates.txt", month, last_month);
	data->bonus_holidays = get_dates("holidays.txt", month, last_month);
}
