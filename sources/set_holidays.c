/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_holidays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:35 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 18:54:56 by hanmpark         ###   ########.fr       */
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
	free_month(holidays);
	return (hdlog);
}

static void	print_holidays(char **holidays, int *stdlog)
{
	int	i;
	int	hdlog;

	i = 0;
	if (holidays)
	{
		ft_printf("%sPUBLIC HOLIDAYS:\n%s", BLUE, DEF);
		while (holidays[i])
		{
			ft_printf("  - %s", holidays[i]);
			i++;
		}
		hdlog = set_hdlog(holidays);
		ft_printf("  => + %s%dh%s\n\n", GREEN, hdlog, DEF);
		stdlog[2] += hdlog;
	}
}

void	set_holidays(int month, int lastmonth, int *stdlog, int *bnlog)
{
	char	**holidays;

	holidays = find_holidays(month, lastmonth);
	print_holidays(holidays, stdlog);
	month = lastmonth;
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	holidays = find_holidays(month, lastmonth);
	bnlog[2] += set_hdlog(holidays);
}
