/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 03:33:18 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

static void	set_currenthdlog(int month, int lastmonth)
{
	char	**holidays;
	int		fd;
	int		hdlog;

	fd = open("holidays.txt", O_RDONLY);
	holidays = parse_month(month, lastmonth, fd);
	close(fd);
	hdlog = 0;
	if (holidays)
	{
		printf("%s\nPUBLIC HOLIDAYS:\n%s", BLUE, DEF);
		while (holidays && holidays[hdlog])
		{
			printf("  - %s", holidays[hdlog]);
			hdlog++;
		}
		hdlog *= 7;
		printf("  %s=> %s%d%s%s hours will be added%s\n\n", ITALIC, GREEN, hdlog, DEF, ITALIC, DEF);
	}
	free_date(holidays);
}

static void	print_result(int month, int lastmonth, char **date, char **bonus_date)
{
	int		i;

	set_currenthdlog(month, lastmonth);
	i = 0;
	if (date)
	{
		printf("%s\nTHE CHOSEN MONTH'S LOGTIMES:\n%s", BLUE, DEF);
		while (date[i])
		{
			printf("  - %s", date[i]);
			i++;
		}
		printf("\n");
	}
	parse_calculation(month, lastmonth, date, bonus_date);
}

static int	find_month(int argc, char *month)
{
	int	res;

	if (argc == 2 && (atoi(month) >= 1 && atoi(month) <= 12))
	{
		res = atoi(month);
		printf("%sChosen month is:%s %d\n", BOLD, DEF, res);
	}
	else if (argc == 2 && (atoi(month) < 1 || atoi(month) > 12))
		return (0);
	else
	{
		res = current_month();
		printf("%sCurrent month:%s %d\n", BOLD, DEF, res);
		if (current_day() >= 27 && current_day() <= 31)
			res++;
		if (res == 13)
			res = 1;
	}
	return (res);
}

static int	set_dates(int month, int lastmonth, char ***date, char ***bonus_date)
{
	int	fd;

	fd = open("dates.txt", O_RDONLY);
	*date = parse_month(month, lastmonth, fd);
	close(fd);
	if (!*date)
	{
		printf("%sCan't calculate for this month...\n\n%s", RED, DEF);
		return (0);
	}
	month = lastmonth;
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	fd = open("dates.txt", O_RDONLY);
	*bonus_date = parse_month(month, lastmonth, fd);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int		month;
	int		lastmonth;
	char	**date;
	char	**bonus_date;

	parse_data();
	parse_holidays();
	month = find_month(argc, argv[1]);
	if (!month)
	{
		printf("%sMonth doesn't exist...\n\n%s", RED, DEF);
		return (-1);
	}
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	if (!(set_dates(month, lastmonth, &date, &bonus_date)))
		return (-1);
	print_result(month, lastmonth, date, bonus_date);
	if (bonus_date)
		free_date(bonus_date);
	free_date(date);
	return (0);
}
