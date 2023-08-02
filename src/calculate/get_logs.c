/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_logs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:55:59 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:44:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

int	find_time(char *src, int time_type)
{
	char	stash[3];
	int		i;

	i = 0;
	while (i < 2)
		stash[i++] = src[time_type++];
	stash[i] = 0;
	return (atoi(stash));
}

bool	cut_max_log(int *logtime)
{
	if (logtime[H] > 140 && logtime[H] < 210)
	{
		logtime[H] -= 140;
		return (true);
	}
	else if (logtime[H] >= 210)
	{
		logtime[H] = 70;
		logtime[MIN] = 0;
		logtime[S] = 0;
		return (true);
	}
	logtime[H] = 0;
	logtime[MIN] = 0;
	logtime[S] = 0;
	return (false);
}

// Calculates all kinds of logtimes to print it all out in the end
t_logtime	*get_logs(t_data data)
{
	t_logtime	*log;

	log = malloc(sizeof(t_logtime));
	if (!log)
		return (NULL);
	log->log = ccl_addlog(data.chosen);
	log->bn_log = ccl_addlog(data.bonus);
	log->hd_log = ccl_hdlog(data.holidays);
	log->log[H] += log->hd_log;
	log->bnhd_log = ccl_hdlog(data.bonus_holidays);
	log->bn_log[H] += log->bnhd_log;
	cut_max_log(log->bn_log);
	log->total_log = ccl_total_logtime(log->log, log->bn_log);
	log->time_left = NULL;
	if (log->total_log[H] < 140 && data.month == current_month())
		log->time_left = ccl_timeleft(log->total_log);
	log->avg_left = NULL;
	return (log);
}
