/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/06 11:58:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

static int	print_result(char **date, char **bonus_date)
{
	int	i;

	i = 0;
	if (!date)
	{
		printf("\033[1;31mThere was a problem looking for the current month...\n\n\033[0m");
		return (0);
	}
	printf("\n");
	printf("\033[1;34mTHE CHOSEN MONTH'S LOGTIMES:\n\033[0m");
	while (date[i])
	{
		printf("  - %s", date[i]);
		i++;
	}
	printf("\n");
	parse_calculation(date, bonus_date);
	if (bonus_date)
		free_date(bonus_date);
	free_date(date);
	return (1);
}

static int	set_month(int argc, char *month)
{
	int	res;

	if (argc == 2 && (atoi(month) >= 1 && atoi(month) <= 12))
	{
		res = atoi(month);
		printf("\033[1mChosen month is:\033[0m %d\n", res);
	}
	else if (argc == 2 && (atoi(month) < 1 || atoi(month) > 12))
		return (0);
	else
	{
		res = current_month();
		printf("\033[1mCurrent month:\033[0m %d\n", res);
	}
	if (res == current_month())
	{
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

	fd = open("texts/text_file.txt", O_RDONLY);
	*date = parse_month(month, fd);
	close(fd);
	if (!date)
	{
		printf("\033[1;31mCan't calculate for this month...\n\n\033[0m");
		return (-1);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	*bonus_date = parse_month(lastmonth, fd);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int		month;
	int		lastmonth;
	char	**date = NULL;
	char	**bonus_date = NULL;

	month = set_month(argc, argv[1]);
	if (!month)
	{
		printf("\033[1;31mThere was a problem looking for the current month...\n\n\033[0m");
		return (-1);
	}
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	if (!(set_dates(month, lastmonth, &date, &bonus_date)))
		return (-1);
	if (!(print_result(date, bonus_date)))
		return (-1);
	return (0);
}
