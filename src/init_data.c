/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 13:16:01 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

#include <string.h>
#include <ctype.h>

static int	set_month(char *month)
{
	if (month && isdigit(*month) && (atoi(month) >= 1 && atoi(month) <= 12))
	{
		printf(CHOSEN_MONTH, atoi(month));
		return (atoi(month));
	}
	else if (month && isdigit(*month) && (atoi(month) < 1 || atoi(month) > 12))
	{
		dprintf(2, NOEXIST_MONTH);
		return (-1);
	}
	printf(CURRENT_MONTH, current_month());
	return (current_month());
}

static bool	set_month_show(char **argv, t_data *data)
{
	int	i;

	data->month = set_month(argv[1]);
	if (data->month == -1)
		return (false);
	i = 0;
	while (argv[++i])
	{
		if (!strcmp(argv[i], "-s"))
			data->show = true;
	}
	return (true);
}

// Initializes the data structure
bool	init_data(char **argv, t_data *data)
{
	setbuf(stdout, NULL);
	parse_json("holidays.txt", HOLIDAYS);
	parse_json("dates.txt", DATES);
	data->chosen = NULL;
	data->bonus = NULL;
	data->holidays = NULL;
	data->bonus_holidays = NULL;
	data->last_month = 0;
	data->month = 0;
	data->show = false;
	data->log = NULL;
	if (!set_month_show(argv, data))
		return (false);
	data->last_month = data->month - 1;
	if (data->month == 1)
		data->last_month = 12;
	return (true);
}

// Frees an array of strings
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
		free(array);
}

// Frees the data structure
void	free_structure(t_data data)
{
	free_array(data.chosen);
	free_array(data.bonus);
	free_array(data.holidays);
	free_array(data.bonus_holidays);
	free(data.log->log);
	free(data.log->bn_log);
	free(data.log->total_log);
	if (data.log->avg_left)
		free(data.log->avg_left);
	if (data.log->time_left)
		free(data.log->time_left);
	free(data.log);
}
