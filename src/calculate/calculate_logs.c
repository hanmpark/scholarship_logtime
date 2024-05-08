/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_logs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:55:38 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/08 10:16:14 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

static int	get_sum_of_time(char **date, int time_type)
{
	int		sum;
	int		i;

	i = -1;
	sum = 0;
	while (date && date[++i])
		sum += find_time(date[i], time_type);
	return (sum);
}

/**
 * Calculates the total of time done during the month:
 * - get the sum of seconds, minutes and hours
 * - store the sum in an array of 3 integers
 */
int	*ccl_addlog(char **month)
{
	int	*sum;

	sum = calloc(3, sizeof(int));
	if (!sum)
		return (NULL);
	sum[S] = get_sum_of_time(month, TXT_SECONDS);
	sum[MIN] = sum[S] / 60;
	sum[S] %= 60;
	sum[MIN] += get_sum_of_time(month, TXT_MINUTES);
	sum[H] = sum[MIN] / 60;
	sum[MIN] %= 60;
	sum[H] += get_sum_of_time(month, TXT_HOURS);
	return (sum);
}

int	*ccl_total_logtime(int *log, int *bnlog)
{
	int	*ttlog;

	ttlog = malloc(3 * sizeof(int));
	if (!ttlog)
		return (NULL);
	ttlog[H] = log[H];
	ttlog[MIN] = log[MIN];
	ttlog[S] = log[S];
	ttlog[S] += bnlog[S];
	if (ttlog[S] > 59)
	{
		ttlog[MIN] += ttlog[S] / 60;
		ttlog[S] %= 60;
	}
	ttlog[MIN] += bnlog[MIN];
	if (ttlog[MIN] > 59)
	{
		ttlog[H] += ttlog[MIN] / 60;
		ttlog[MIN] %= 60;
	}
	ttlog[H] += bnlog[H];
	return (ttlog);
}

int	*ccl_timeleft(int *ttlog)
{
	int	*time_left;

	time_left = malloc(3 * sizeof(int));
	if (!time_left)
		return (NULL);
	time_left[H] = ttlog[H];
	time_left[MIN] = ttlog[MIN];
	time_left[S] = ttlog[S];
	if (time_left[S] > 0)
	{
		time_left[S] = 60 - time_left[S];
		time_left[MIN]++;
	}
	if (time_left[MIN] > 0)
	{
		time_left[MIN] = 60 - time_left[MIN];
		time_left[H]++;
	}
	time_left[H] = 140 - time_left[H];
	return (time_left);
}

int	ccl_hdlog(char **holidays)
{
	int	hdlog;

	if (!holidays)
		return (0);
	hdlog = 0;
	while (holidays[hdlog])
		hdlog++;
	hdlog *= 7;
	return (hdlog);
}
