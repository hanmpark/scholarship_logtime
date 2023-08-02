/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:53:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

static char	*get_color(int avg_hour)
{
	if (avg_hour < 13)
		return (GREEN);
	else if (avg_hour < 24)
		return (YELLOW);
	return (RED);
}

static void	incomplete_logtime(t_logtime *log)
{
	log->avg_left = ccl_avgleft(&log->dleft, log->time_left);
	printf(PRINT_TIME_LEFT, log->time_left[H], log->time_left[MIN], log->time_left[S]);
	printf(PRINT_DAYS_LEFT, log->dleft);
	printf(PRINT_TO_DO, get_color(log->avg_left[H]), log->avg_left[H], log->avg_left[MIN], log->avg_left[S]);
}

/* Checks the logtime
* - if some time is still left to do the minimum of hours,
* prints useful information to be able to fulfill them
* - else checks if it can store bonus hours for next month or not
*/
void	check_logtime(t_logtime *log)
{
	printf("------------------------------------------------------\n");
	if (log->time_left)
		incomplete_logtime(log);
	else if (cut_max_log(log->log))
	{
		printf(LOGTIME_OK);
		printf(PRINT_NEXT_BONUS, log->log[H], log->log[MIN], log->log[S]);
	}
	else
		printf(NOTHING);
	printf("------------------------------------------------------\n\n");
}
