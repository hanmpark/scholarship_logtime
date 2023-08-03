/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:17:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/03 21:46:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

#include <string.h>
#include <ctype.h>

static void	set_show_flag(char **argv, t_data *data)
{
	while (*argv)
	{
		if (!strcmp(*argv, "-s"))
			data->show = true;
		argv++;
	}
}

// Initializes the data structure
void	init_data(char **argv, t_data *data)
{
	setbuf(stdout, NULL);
	data->chosen = NULL;
	data->bonus = NULL;
	data->holidays = NULL;
	data->bonus_holidays = NULL;
	data->last_month = 0;
	data->month = atoi(argv[1]);
	data->show = false;
	data->log = NULL;
	set_show_flag(argv, data);
	data->last_month = data->month - 1;
	if (data->month == 1)
		data->last_month = 12;
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
