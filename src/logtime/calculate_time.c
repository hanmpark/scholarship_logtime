/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:55:59 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:23:28 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "calculate_time.h"
#include "print.h"

static int	find_time(char **date, int time)
{
	char	stash[3];
	int		i;
	int		k;
	int		res;

	i = -1;
	res = 0;
	while (date && date[++i])
	{
		k = 0;
		while (k < 2)
			stash[k++] = date[i][time++];
		stash[k] = 0;
		res += atoi(stash);
		time -= 2;
	}
	return (res);
}

int	*ccl_addlog(char **date)
{
	int	*res;

	res = malloc(3 * sizeof(int));
	if (!res)
		return (0);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[0] = find_time(date, 20);
	res[1] = res[0] / 60;
	res[0] %= 60;
	res[1] += find_time(date, 17);
	res[2] = res[1] / 60;
	res[1] %= 60;
	res[2] += find_time(date, 14);
	return (res);
}

int	*ccl_total_logtime(int *stdlog, int *bnlog)
{
	int	*ttlog;

	print_bnlog(stdlog, bnlog);
	ttlog = malloc(3 * sizeof(int));
	ttlog[2] = stdlog[2];
	ttlog[1] = stdlog[1];
	ttlog[0] = stdlog[0];
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
	return (ttlog);
}

void	ccl_timeleft(int *ttlog)
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

int	ccl_hdlog(char **holidays)
{
	int	hdlog;

	if (!holidays)
		return (0);
	hdlog = 0;
	while (holidays[hdlog])
		hdlog++;
	hdlog *= 7;
	free_month(holidays);
	return (hdlog);
}
