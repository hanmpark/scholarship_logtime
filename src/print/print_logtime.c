/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/03 23:38:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

static void	print_bnlog(int *stdlog, int *bnlog)
{
	if (!bnlog[H] && !bnlog[MIN] && !bnlog[S])
		return ;
	printf(PRINT_BNLOG, bnlog[2], bnlog[1], bnlog[0]);
	printf(PRINT_WITHOUT_BN, stdlog[2], stdlog[1], stdlog[0]);
}

static void	print_month(char *title, char **dates, int holidays)
{
	int	i;

	i = -1;
	if (!dates)
		return ;
	printf("%s", title);
	while (dates[++i])
		printf("  - %s", dates[i]);
	if (holidays)
		printf(PRINT_HD_HOURS, holidays);
}

// Prints every important information
void	print_logtime(t_data data)
{
	t_logtime	*log;

	log = data.log;
	if (data.show == true)
	{
		print_month(PRINT_MONTH, data.chosen, 0);
		print_month(PRINT_HD, data.holidays, log->hd_log);
	}
	print_bnlog(log->log, log->bn_log);
	printf(PRINT_TOTAL_TIME, log->total_log[H], log->total_log[MIN], log->total_log[S]);
	check_logtime(log);
	print_progressbar(log->total_log[H], 140);
}
