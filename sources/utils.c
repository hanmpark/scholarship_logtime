/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 13:38:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
#include <time.h>

/* CLEAR DATE */
void	free_date(char **date)
{
	int	i;

	i = 0;
	while (i < 32)
		free(date[i++]);
	free(date);
}

void	print_progress(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	i = 0;
	printf("|");
	prct = 100 * tthours / hours;
	printprct = 23 * prct / 100;
	if (prct < 26)
		color = RED;
	else if (prct < 76)
		color = YELLOW;
	else
		color = GREEN;
	while (i++ < printprct && i < 23)
		printf("%s▰%s", color, DEF);
	while (i++ < 23)
		printf("-");
	printf("| ");
	printf("%s%d%%%s\n\n", color, prct, DEF);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

char	**find_holidays(int month, int lastmonth)
{
	char	**holidays;
	int		fd;

	fd = open("holidays.txt", O_RDONLY);
	holidays = parse_month(month, lastmonth, fd);
	close(fd);
	return (holidays);
}

int	set_hdlog(char **holidays)
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
