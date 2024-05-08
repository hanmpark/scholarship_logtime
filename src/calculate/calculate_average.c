/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_average.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:42:05 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/08 10:17:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

static int	set_days_off(void)
{
	int	days_off;

	printf(PRINT_ASK_DAYSOFF);
	scanf("%d", &days_off);
	if (days_off < 0 || days_off >= days_left())
	{
		printf(PRINT_INCOMPATIBLE_DAYSOFF);
		days_off = 0;
	}
	printf(PRINT_DAYSOFF, days_off);
	return (days_off);
}

int	*ccl_avgleft(int *dleft, int *time_left)
{
	int	*avg_left;
	int	total_seconds;
	int	avg_time_per_day;
	int	remaining_seconds;

	avg_left = calloc(3, sizeof(int));
	if (!avg_left)
		return (NULL);
	total_seconds = time_left[S] + time_left[MIN] * 60 + time_left[H] * 3600;
	*dleft = days_left() - set_days_off();
	avg_time_per_day = total_seconds / *dleft;
	avg_left[H] = avg_time_per_day / 3600;
	remaining_seconds = avg_time_per_day % 3600;
	avg_left[MIN] = remaining_seconds / 60;
	avg_left[S] = remaining_seconds % 60;
	return (avg_left);
}
