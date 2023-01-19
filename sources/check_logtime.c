/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 19:38:01 by hanmpark         ###   ########.fr       */
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

static int	set_days_off(void)
{
	int		days_off;

	ft_printf("%s%sThe number of days you want to take off from now on:%s%s ", ITALIC, GRAY, DEF, GREEN);
	scanf("%d", &days_off);
	if (days_off < 0 || days_off >= days_left())
	{
		ft_printf("%s%s\t\tIncompatible days off%s\n", ITALIC, RED, DEF);
		days_off = 0;
	}
	ft_printf("%s%sDays off : %s%d%s\n", DEF, BOLD, GREEN, days_off, DEF);
	return (days_off);
}

static void	incomplete_logtime(int *ttlog)
{
	int	dleft;
	int	hours_left;
	int	minutes_left;
	int	seconds_left;

	ccl_timeleft(ttlog);
	dleft = days_left() - set_days_off();
	hours_left = ttlog[2] / dleft;
	minutes_left = ((ttlog[2] % dleft) * 60 + ttlog[1]) / dleft;
	seconds_left = ((((ttlog[2] % dleft) * 60 + ttlog[1]) % dleft) * 60 + ttlog[0]) / dleft;
	ft_printf("%sTime left: %s%dh %dmin %ds%s\n", BOLD, GREEN,
		ttlog[2], ttlog[1], ttlog[0], DEF);
	ft_printf("%sDays left: %s%d days%s\n", BOLD, GREEN, dleft, DEF);
	if (hours_left < 13)
	{
		ft_printf("%sTo do log: %s%dh %dmin %ds / day%s\n", BOLD, GREEN,
			hours_left, minutes_left, seconds_left, DEF);
	}
	else if (hours_left < 24)
	{
		ft_printf("%sTo do log: %s%dh %dmin %ds / day%s\n", BOLD, YELLOW,
			hours_left, minutes_left, seconds_left, DEF);
	}
	else
	{
		ft_printf("%sTo do log: %s%dh %dmin %ds / day%s\n", BOLD, RED,
			hours_left, minutes_left, seconds_left, DEF);
		ft_printf("%s%s\t   sorry it's impossible%s\n", ITALIC, RED, DEF);
	}
}

void	check_logtime(int month, int *stdlog, int *ttlog)
{
	ft_printf("------------------------------------------------------\n");
	if (ttlog[2] < 140 && month == current_month())
		incomplete_logtime(ttlog);
	else if (stdlog[2] >= 140 && stdlog[2] < 210)
	{
		stdlog[2] -= 140;
		ft_printf("%s%s\t\t     LOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		ft_printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else if (stdlog[2] >= 210)
	{
		stdlog[2] = 70;
		stdlog[1] = 0;
		stdlog[0] = 0;
		ft_printf("%s%s\t\t     LOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		ft_printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN,
			stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else
	{
		ft_printf("%s%s\t\t     LOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		ft_printf("%s\t\tNothing for next month%s\n", PURPLE, DEF);
	}
	ft_printf("------------------------------------------------------\n\n");
}
