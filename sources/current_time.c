/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:20:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/18 14:52:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static int	number_of_days(int year, int month)
{
	int	days_in_month;

	switch (month) {
		case 0: days_in_month = 31; break;
		case 1:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				days_in_month = 29;
			else
				days_in_month = 28;
			break ;
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
	return (days_in_month);
}

int	day_left(void)
{
	time_t		t;
	struct tm	*tm;
	int			year;
	int			month;
	int			days_left;
	
	time(&t);
	tm = localtime(&t);
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
			year -= 1;
		}
		else
			month--;
		days_left = (number_of_days(year, month) - 1) - (number_of_days(year, month) - 27) - tm->tm_mday;
	}
	return (days_left);
}

int	current_month(void)
{
	time_t		t;
	struct tm	*tm;
	
	time(&t);
	tm = localtime(&t);
	return (tm->tm_mon + 1);
}

int	current_day(void)
{
	time_t		t;
	struct tm	*tm;

	time(&t);
	tm = localtime(&t);
	return (tm->tm_mday);
}