/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:20:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:13:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "find_time.h"

static int	number_of_days(int year, int month)
{
	int	days_in_month;

	switch (month) {
		case 0: days_in_month = 31; break;
		case 2: days_in_month = 31; break;
		case 3: days_in_month = 30; break;
		case 4: days_in_month = 31; break;
		case 5: days_in_month = 30; break;
		case 6: days_in_month = 31; break;
		case 7: days_in_month = 31; break;
		case 8: days_in_month = 30; break;
		case 9: days_in_month = 31; break;
		case 10: days_in_month = 30; break;
		case 11: days_in_month = 31; break;
	}
	if (month == 1)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			days_in_month = 29;
		else
			days_in_month = 28;
	}
	return (days_in_month);
}

static struct tm	*set_tm(void)
{
	time_t		t;
	struct tm	*tm;

	time(&t);
	tm = localtime(&t);
	return (tm);
}

int	days_left(void)
{
	struct tm	*tm;
	int			year;
	int			month;
	int			days_left;
	
	tm = set_tm();
	year = tm->tm_year + 1900;
	month = tm->tm_mon;
	days_left = 0;
	if (tm->tm_mday >= 27 && tm->tm_mday <= 31)
		days_left = (number_of_days(year, month) - 1) - (tm->tm_mday - 27);
	else if (tm->tm_mday >= 1 && tm->tm_mday <= 26)
	{
		if (month == 0)
		{
			month = 11;
			year--;
		}
		else
			month--;
		days_left = (number_of_days(year, month) - 1) - (number_of_days(year, month) - 27) - tm->tm_mday + 1;
	}
	return (days_left);
}

int	current_month(void)
{
	struct tm	*tm;
	int			month;
	
	tm = set_tm();
	month = tm->tm_mon + 1;
	if (current_day() >= 27 && current_day() <= 31)
		month++;
	if (month == 13)
		month = 1;
	return (month);
}

int	current_day(void)
{
	struct tm	*tm;

	tm = set_tm();
	return (tm->tm_mday);
}

int	current_year(void)
{
	struct tm	*tm;

	tm = set_tm();
	return (tm->tm_year + 1900);
}
