/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:20:20 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/22 23:40:59 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
#include <time.h>

int	number_of_days(int year, int month)
{
	int			days_in_month;

	switch (month) {
		case 0:  days_in_month = 31; break; // January
		case 2:  days_in_month = 31; break; // March
		case 3:  days_in_month = 30; break; // April
		case 4:  days_in_month = 31; break; // May
		case 5:  days_in_month = 30; break; // June
		case 6:  days_in_month = 31; break; // July
		case 7:  days_in_month = 31; break; // August
		case 8:  days_in_month = 30; break; // September
		case 9:  days_in_month = 31; break; // October
		case 10: days_in_month = 30; break; // November
		case 11: days_in_month = 31; break; // December
	}
	if (month == 1) // February
	{
		// Check leap year
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			days_in_month = 29;
		else
			days_in_month = 28;
	}
	return (days_in_month);
}

int	day_left(void)
{
	time_t		t;
	struct tm	*tm;
	int			days_in_month;
	int			current_day;
	int			year;
	int			month;
	int			days_left;
	
	time(&t);
	tm = localtime(&t);
	current_day = tm->tm_mday;
	year = tm->tm_year + 1900;
	month = tm->tm_mon;
	days_in_month = 0;
	if (current_day >= 27 && current_day <= 31)
		days_in_month = number_of_days(year, month);
	else if (current_day >= 1 && current_day <= 26)
	{
		if (month == 0)
		{
			month = 11;
			year -= 1;
		}
		else
			month--;
		days_in_month = number_of_days(year, month);
	}
	days_left = (days_in_month - 1) - (days_in_month - 27) - current_day;
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