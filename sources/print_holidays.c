/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_holidays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 13:52:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static char	**find_holidays(int month, int lastmonth)
{
	char	**holidays;
	int		fd;

	fd = open("holidays.txt", O_RDONLY);
	holidays = parse_month(month, lastmonth, fd);
	close(fd);
	return (holidays);
}

static int	set_hdlog(char **holidays)
{
	int	hdlog;

	if (!holidays)
		return (0);
	hdlog = 0;
	while (holidays[hdlog])
		hdlog++;
	hdlog *= 7;
	free_date(holidays);
	return (hdlog);
}

void	printset_holidays(int month, int lastmonth, int *stdlog, int *bnlog)
{
	int		hdlog;
	char	**holidays;

	holidays = find_holidays(month, lastmonth);
	hdlog = 0;
	if (holidays)
	{
		printf("%sPUBLIC HOLIDAYS:\n%s", BLUE, DEF);
		while (holidays[hdlog])
		{
			printf("  - %s", holidays[hdlog]);
			hdlog++;
		}
		hdlog *= 7;
		printf("  %s=> %s%d%s%s hours will be added%s\n\n", ITALIC, GREEN, hdlog, DEF, ITALIC, DEF);
		free_date(holidays);
	}
	stdlog[2] += hdlog;
	month = lastmonth;
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	holidays = find_holidays(month, lastmonth);
	hdlog = set_hdlog(holidays);
	bnlog[2] += hdlog;
}
