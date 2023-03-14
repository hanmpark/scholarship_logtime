/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:24:47 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "calculate_time.h"
#include "find_time.h"
#include <string.h>
#include "print.h"

void	print_bnlog(int *stdlog, int *bnlog)
{
	if (bnlog[2] >= 140 && bnlog[2] < 210)
	{
		bnlog[2] -= 140;
		printf("\n%sBonus log: %s%dh %dmin %ds%s\n\n", BOLD, GREEN,
			bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds%s", CYAN, UL,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else if (bnlog[2] >= 210)
	{
		bnlog[2] = 70;
		bnlog[1] = 0;
		bnlog[0] = 0;
		printf("\n%sBonus log: %s%dh %dmin %ds%s\n\n", BOLD, GREEN,
			bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds%s", CYAN, UL,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else
	{
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
	}
}

void	print_holidays(char **holidays, int *stdlog, int show)
{
	int	i;
	int	hdlog;

	i = 0;
	if (holidays && show)
	{
		printf("\n%sPUBLIC HOLIDAYS:%s\n", BLUE, DEF);
		while (holidays[i])
		{
			printf("  - %s", holidays[i]);
			i++;
		}
		hdlog = ccl_hdlog(holidays);
		printf("  => + %s%dh%s\n", GREEN, hdlog, DEF);
		stdlog[2] += hdlog;
	}
	else if (!show)
	{
		hdlog = ccl_hdlog(holidays);
		stdlog[2] += hdlog;
	}
}

static int	animated_bar(char *color, int prct, int printprct)
{
	int		i;
	char	*prctstr;

	i = 0;
	printf("[");
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%", color, prct);
	prctstr = ft_itoa(prct);
	i += (int)strlen(prctstr) + 2;
	free(prctstr);
	while (i--)
		printf("\b");
	while (i++ < printprct && i < 31)
	{
		printf("%s▰%s", color, DEF);
		usleep(50000);
	}
	return (i);
}

static void	print_progressbar(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	i = 0;
	prct = 100 * tthours / hours;
	printprct = 31 * prct / 100;
	if (prct < 26)
		color = RED;
	else if (prct < 76)
		color = YELLOW;
	else
		color = GREEN;
	i = animated_bar(color, prct, printprct);
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%%s\n\n", color, prct, DEF);
}

static void	print_info(t_data *data)
{
	int		*stdlog;
	int		*bnlog;
	int		*ttlog;
	int		tthours;

	stdlog = ccl_addlog(data->chosen);
	bnlog = ccl_addlog(data->bonus);
	set_holidays(data, stdlog, bnlog);
	ttlog = ccl_total_logtime(stdlog, bnlog);
	tthours = ttlog[2];
	printf("\n%s%sTotal logtime = %s%dh %dmin %ds%s\n\n", CYAN, BOLD, UL,
		ttlog[2], ttlog[1], ttlog[0], DEF);
	check_logtime(data->month, stdlog, ttlog);
	printf("%s%sProgress log:%s\t", UL, PURPLE, DEF);
	print_progressbar(tthours, 140);
	free(ttlog);
	free(stdlog);
}

void	print_result(t_data *data)
{
	int		i;

	i = 0;
	if (data->chosen && data->show_dates == 1)
	{
		printf("%s\nTHE CHOSEN MONTH'S LOGTIMES:%s\n", BLUE, DEF);
		while (data->chosen[i])
		{
			printf("  - %s", data->chosen[i]);
			i++;
		}
	}
	print_info(data);
}

int	set_month(char *month)
{
	int	res;

	if (month && ft_isdigit(*month) && (atoi(month) >= 1 && atoi(month) <= 12))
	{
		res = atoi(month);
		printf("%s%s- [INFO] Chosen month:%s %d\n", BACK, GRAY, DEF, res);
	}
	else if (month && ft_isdigit(*month) && (atoi(month) < 1 || atoi(month) > 12))
	{
		printf("%s%s- [ERROR] Month doesn't exist...%s\n\n", BACK, RED, DEF);
		exit(1);
	}
	else
	{
		res = current_month();
		printf("%s%s- [INFO] Current month:%s %d\n", BACK, GRAY, DEF, res);
	}
	return (res);
}
