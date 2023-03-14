/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_holidays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:25:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "calculate_time.h"
#include "find_time.h"
#include "parse.h"
#include "print.h"
#include <fcntl.h>

static char	**find_holidays(int month, int lastmonth)
{
	char	**holidays;
	int		fd;

	fd = open("holidays.txt", O_RDONLY);
	holidays = parse_month(month, lastmonth, fd);
	close(fd);
	return (holidays);
}

void	set_holidays(t_data *data, int *stdlog, int *bnlog)
{
	char	**holidays;
	int		month;
	int		last_month;

	month = data->month;
	last_month = data->last_month;
	holidays = find_holidays(month, last_month);
	print_holidays(holidays, stdlog, data->show_dates);
	month = last_month;
	last_month = month - 1;
	if (month == 1)
		last_month = 12;
	holidays = find_holidays(month, last_month);
	bnlog[2] += ccl_hdlog(holidays);
}
