/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/16 20:40:31 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

/* CALCULATES TIME NOT PARSED */
int	ccl_time(char **date, int itype)
{
	int		idate = -1;
	int		og_itype = itype;
	int		index = 0;
	char	stash[3];
	int		res = 0;

	while (date[++idate])
	{
		itype = og_itype;
		index = 0;
		while (index < 2)
			stash[index++] = date[idate][itype++];
		stash[index] = 0;
		res += atoi(stash);
	}
	return (res);
}

/* PARSING OF LOGTIME */
int	*ccl_log(char **date)
{
	int	*res;

	res = malloc(3 * sizeof(int));
	if (!res)
		return (NULL);
	/* CALCULATES SECONDS */
	res[0] = 0; // seconds
	res[1] = 0; // minutes
	res[2] = 0; // hours
	/* CALCULATES MINUTES */
	res[0] = ccl_time(date, 18);
	res[1] = res[0] / 60;
	res[0] %= 60;
	/* CALCULATES HOURS */
	res[1] += ccl_time(date, 15);
	res[2] = res[1] / 60;
	res[1] %= 60;
	res[2] += ccl_time(date, 12);
	return (res);
}

/* MAX BONUS = 70 AND BONUS = EXTRA TIME AFTER 140 HOURS */
void	set_bnlog(int *stdlog, int *bnlog)
{
	if (bnlog[2] >= 140 && bnlog[2] < 210)
	{
		bnlog[2] -= 140;
		printf("%sBonus log: %s%dh %dmin %ds\n\n%s", BOLD, GREEN, bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds\n%s", CYAN, UL, stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else if (bnlog[2] >= 210)
	{
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 70;
		printf("%sBonus log: %s%dh %dmin %ds\n\n%s", BOLD, GREEN, bnlog[2], bnlog[1], bnlog[0], DEF);
		printf("%sWithout bonus = %s%dh %dmin %ds\n%s", CYAN, UL, stdlog[2], stdlog[1], stdlog[0], DEF);
	}
	else
	{
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
	}
}

int	*ccl_total_time(char **date, int *bnlog)
{
	int	*ttlog;
	int	*stdlog;

	stdlog = ccl_log(date);
	set_bnlog(stdlog, bnlog);
	ttlog = ccl_log(date);
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
	free(stdlog);
	return (ttlog);
}

static void	print_progress_bn(int tthours)
{
	int		i;
	int		prct;
	int		printprct;

	i = 0;
	printf("|");
	prct = 100 * tthours / 70;
	printprct = 23 * prct / 100;
	while (i++ < printprct && i < 23)
		printf("%s▰%s", YELLOW, DEF);
	while (i++ < 23)
		printf("-");
	printf("| ");
	printf("%s%d%%%s\n", YELLOW, prct, DEF);
}

/* CHECKS TIME LEFT OR ADDITIONAL TIME OR DONE */
void	check_logtime(int *stdlog, int *ttlog)
{
	int	dleft;

	if (ttlog[2] < 140)
	{
		ccl_timeleft(ttlog);
		dleft = day_left();
		if (dleft > 0)
		{
			int	hours_left;
			int	minutes_left;
			int	seconds_left;
			hours_left = ttlog[2] / dleft;
			minutes_left = ((ttlog[2] % dleft) * 60 + ttlog[1]) / dleft;
			seconds_left = ((((ttlog[2] % dleft) * 60 + ttlog[1]) % dleft) * 60 + ttlog[0]) / dleft;
			printf("-----------------------------\n");
			printf("%sTime left: %s%dh %dmin %ds%s\n", BOLD, GREEN, ttlog[2], ttlog[1], ttlog[0], DEF);
			printf("%sDays left: %s%d days%s\n", BOLD, GREEN, dleft, DEF);
			printf("%sTo do log: %s%dh %dmin %ds / day%s\n", BOLD, GREEN, hours_left, minutes_left, seconds_left, DEF);
			printf("-----------------------------\n\n");
		}
		else if (dleft == 0)
		{
			printf("-----------------------------\n");
			printf("%sTo do log: %s%dh %dmin %ds%s\n", BOLD, GREEN, ttlog[2], ttlog[1], ttlog[0], DEF);
			printf("-----------------------------\n\n");
		}
	}
	else if (stdlog[2] >= 140 && stdlog[2] < 210)
	{
		stdlog[2] -= 140;
		printf("%s%s\tLOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		printf("-----------------------------\n");
		printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN, stdlog[2], stdlog[1], stdlog[0], DEF);
		print_progress_bn(stdlog[2]);
		printf("-----------------------------\n\n");
	}
	else if (stdlog[2] >= 210)
	{
		stdlog[2] = 70;
		stdlog[1] = 0;
		stdlog[0] = 0;
		printf("%s%s\tLOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
		printf("-----------------------------\n");
		printf("%sNext month bonus: %s%dh %dmin %ds%s\n", PURPLE, GREEN, stdlog[2], stdlog[1], stdlog[0], DEF);
		print_progress_bn(stdlog[2]);
		printf("-----------------------------\n\n");
	}
	else
		printf("%s%s\tLOGTIME OK !%s\n\n", GREEN, ITALIC, DEF);
}
