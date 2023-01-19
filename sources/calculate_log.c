/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 04:27:45 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static int	ccl_time(char **date, int time)
{
	char	stash[3];
	int		i;
	int		k;
	int		res;

	i = -1;
	res = 0;
	while (date && date[++i])
	{
		k = 0;
		while (k < 2)
			stash[k++] = date[i][time++];
		stash[k] = 0;
		res += atoi(stash);
		time -= 2;
	}
	return (res);
}

static int	*ccl_log(char **date)
{
	int	*res;

	res = malloc(3 * sizeof(int));
	if (!res)
		return (NULL);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[0] = ccl_time(date, 18);
	res[1] = res[0] / 60;
	res[0] %= 60;
	res[1] += ccl_time(date, 15);
	res[2] = res[1] / 60;
	res[1] %= 60;
	res[2] += ccl_time(date, 12);
	return (res);
}

static void	set_bnlog(int *stdlog, int *bnlog)
{
	if (bnlog[2] >= 140 && bnlog[2] < 210)
	{
		bnlog[2] -= 140;
		printf("%sBonus log: %s%dh %dmin %ds\n\n%s", BOLD, GREEN,
			bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds\n%s", CYAN, UL,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else if (bnlog[2] >= 210)
	{
		bnlog[2] = 70;
		bnlog[1] = 0;
		bnlog[0] = 0;
		printf("%sBonus log: %s%dh %dmin %ds\n\n%s", BOLD, GREEN,
			bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds\n%s", CYAN, UL,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else
	{
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
	}
}

static int	*ccl_total_time(int *stdlog, int *bnlog)
{
	int	*ttlog;

	set_bnlog(stdlog, bnlog);
	ttlog = malloc(3 * sizeof(int));
	ttlog[2] = stdlog[2];
	ttlog[1] = stdlog[1];
	ttlog[0] = stdlog[0];
	ttlog[0] += bnlog[0];
	if (ttlog[0] > 59)
	{
		ttlog[1] += ttlog[0] / 60;
		ttlog[0] %= 60;
	}
	ttlog[1] += bnlog[1];
	if (ttlog[1] > 59)
	{
		ttlog[2] += ttlog[1] / 60;
		ttlog[1] %= 60;
	}
	ttlog[2] += bnlog[2];
	free(bnlog);
	return (ttlog);
}

static int	set_hdlog(int month, int lastmonth)
{
	char	**holidays;
	int		fd;
	int		hdlog;

	fd = open("holidays.txt", O_RDONLY);
	holidays = parse_month(month, lastmonth, fd);
	close(fd);
	hdlog = 0;
	while (holidays && holidays[hdlog])
		hdlog++;
	hdlog *= 7;
	if (holidays)
		free_date(holidays);
	return (hdlog);
}

void	parse_calculation(int month, int lastmonth, char **date, char **bonus_date)
{
	int	*stdlog;
	int	*bnlog;
	int	*ttlog;
	int	hdlog;
	int	tthours;

	stdlog = ccl_log(date);
	printf("month = %d lastmonth = %d\n", month, lastmonth);
	hdlog = set_hdlog(month, lastmonth);
	printf("hdlog = %d\n", set_hdlog(month, lastmonth));
	stdlog[2] += hdlog;
	bnlog = ccl_log(bonus_date);
	month = lastmonth;
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	hdlog = set_hdlog(month, lastmonth);
	bnlog[2] += hdlog;
	ttlog = ccl_total_time(stdlog, bnlog);
	tthours = ttlog[2];
	printf("%s%sTotal logtime = %s%dh %dmin %ds%s\n\n", CYAN, BOLD, UL,
		ttlog[2], ttlog[1], ttlog[0], DEF);
	check_logtime(month, stdlog, ttlog);
	printf("%s%sProgress log:%s\t", UL, PURPLE, DEF);
	print_progress(tthours, 140);
	free(ttlog);
	free(stdlog);
}
