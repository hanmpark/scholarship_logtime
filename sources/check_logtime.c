/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 02:49:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static void	ccl_timeleft(int *ttlog)
{
	if (ttlog[0] > 0)
	{
		ttlog[0] = 60 - ttlog[0];
		ttlog[1]++;
	}
	if (ttlog[1] > 0)
	{
		ttlog[1] = 60 - ttlog[1];
		ttlog[2]++;
	}
	ttlog[2] = 140 - ttlog[2];
}

static void	incomplete_logtime(int *ttlog)
{
	int	dleft;
	int	days_off;
	int	hours_left;
	int	minutes_left;
	int	seconds_left;

	ccl_timeleft(ttlog);
	printf("%s%sThe number of days you want to take off from now on:%s%s ", ITALIC, GRAY, DEF, GREEN);
	scanf("%d", &days_off);
	printf("%s%sDays off : %s%d%s\n", DEF, BOLD, GREEN, days_off, DEF);
	if (days_off < 0 || days_off >= days_left())
	{
		printf("%s%sIncompatible days off%s\n", ITALIC, GRAY, DEF);
		days_off = 0;
	}
	dleft = days_left() - days_off;
	if (dleft <= 0)
		dleft = 1;
	hours_left = ttlog[2] / dleft;
	minutes_left = ((ttlog[2] % dleft) * 60 + ttlog[1]) / dleft;
	seconds_left = ((((ttlog[2] % dleft) * 60 + ttlog[1]) % dleft) * 60 + ttlog[0]) / dleft;
	printf("%sTime left: %s%dh %dmin %ds%s\n", BOLD, GREEN,
		ttlog[2], ttlog[1], ttlog[0], DEF);
	printf("%sDays left: %s%d days%s\n", BOLD, GREEN, dleft, DEF);
	printf("%sTo do log: %s%dh %dmin %ds / day%s\n", BOLD, GREEN,
		hours_left, minutes_left, seconds_left, DEF);
}

void	check_logtime(int month, int *stdlog, int *ttlog)
{
	if (ttlog[2] < 140 && month == current_month())
	{
		printf("------------------------------------------------------\n");
		incomplete_logtime(ttlog);
		printf("------------------------------------------------------\n\n");
		return ;
	}
	else if (stdlog[2] >= 140 && stdlog[2] < 210)
	{
		stdlog[2] -= 140;
		printf("------------------------------------------------------\n");
		printf("%s%s\t\t     LOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN,
			stdlog[2], stdlog[1], stdlog[0], DEF);
		printf("------------------------------------------------------\n\n");
	}
	else if (stdlog[2] >= 210)
	{
		stdlog[2] = 70;
		stdlog[1] = 0;
		stdlog[0] = 0;
		printf("------------------------------------------------------\n");
		printf("%s%s\t\t     LOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN,
			stdlog[2], stdlog[1], stdlog[0], DEF);
		printf("------------------------------------------------------\n\n");
	}
}
