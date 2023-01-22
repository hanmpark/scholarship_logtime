/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/21 19:08:27 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

static void	print_result(int month, int lmonth, char **date, char **bonus_date, int show)
{
	int		i;

	i = 0;
	if (date && show == 1)
	{
		printf("%s\nTHE CHOSEN MONTH'S LOGTIMES:%s\n", BLUE, DEF);
		while (date[i])
		{
			printf("  - %s", date[i]);
			i++;
		}
	}
	ccl_logtime(month, lmonth, date, bonus_date, show);
}

static int	find_month(char *month)
{
	int	res;

	if (month && ft_isdigit(*month) && (ft_atoi(month) >= 1 && ft_atoi(month) <= 12))
	{
		res = atoi(month);
		printf("%s%s- [INFO] Chosen month:%s %d\n", BACK, GRAY, DEF, res);
	}
	else if (month && ft_isdigit(*month) && (ft_atoi(month) < 1 || ft_atoi(month) > 12))
	{
		printf("%s%s- [ERROR] Month doesn't exist...%s\n\n", BACK, RED, DEF);
		exit(1);
	}
	else
	{
		res = current_month();
		printf("%s%s- [INFO] Current month:%s %d\n", BACK, GRAY, DEF, res);
		if (current_day() >= 27 && current_day() <= 31)
			res++;
		if (res == 13)
			res = 1;
	}
	return (res);
}

static int	set_dates(int month, int lmonth, char ***date, char ***bonus_date)
{
	int	fd;

	fd = open("dates.txt", O_RDONLY);
	*date = parse_month(month, lmonth, fd);
	close(fd);
	if (!*date)
	{
		printf("%s- [ERROR] Can't calculate for this month...%s\n\n", RED, DEF);
		return (0);
	}
	month = lmonth;
	lmonth = month - 1;
	if (month == 1)
		lmonth = 12;
	fd = open("dates.txt", O_RDONLY);
	*bonus_date = parse_month(month, lmonth, fd);
	close(fd);
	return (1);
}

static void	set_info(int argc, char **argv, int *month, int *show)
{
	int	i;

	*show = 0;
	*month = 0;
	if (argc == 3)
	{
		i = 1;
		while (argv[i])
		{
			if (!*month && ft_atoi(argv[i]))
				*month = find_month(argv[i]);
			if (!strcmp(argv[i], "-s"))
				*show = 1;
			i++;
		}
		if (!*month)
			*month = find_month(argv[1]);
	}
	else if (argc == 2)
	{
		*month = find_month(argv[1]);
		if (!strcmp(argv[1], "-s"))
			*show = 1;
	}
	else
		*month = find_month(argv[1]);
}

int	main(int argc, char **argv)
{
	int		month;
	int		lastmonth;
	char	**date;
	char	**bonus_date;
	int		show;

	api_dates();
	api_public_holidays();
	set_info(argc, argv, &month, &show);
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	if (!(set_dates(month, lastmonth, &date, &bonus_date)))
		return (1);
	print_result(month, lastmonth, date, bonus_date, show);
	if (bonus_date)
		free_month(bonus_date);
	free_month(date);
	return (0);
}
