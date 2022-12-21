/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:53:20 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/21 04:36:43 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

void	parse_calculation(char **date, char **bonus_date)
{
	int	*stdlog;
	int	*bnlog;
	int	*ttlog;
	
	stdlog = ccl_log(date);
	if (bonus_date)
		bnlog = ccl_log(bonus_date);
	else
	{
		(void)bonus_date;
		bnlog = malloc(3 * sizeof(char));
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
		printf("\033[0;31mCan't calculate for bonus logtime...\n\033[0m");
	}
	ttlog = ccl_total_time(date, bnlog);
	printf("\033[1;36m\tTotal logtime = \033[4m%dh %dmin %ds\033[0m\033[1;36m\n\n\033[0m", ttlog[2], ttlog[1], ttlog[0]);
	check_logtime(stdlog, ttlog);
	free(ttlog);
	free(stdlog);
}

char	**parse_month(int month, int fd)
{
	char	**str;
	int		lastmonth;

	str = calloc(32, sizeof(char *));
	if (!str)
		return (NULL);
	if (month == 1)
		lastmonth = 12;
	else
		lastmonth = month - 1;
	str[0] = get_day(month, lastmonth, fd);
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	get_month(str, month, lastmonth, fd);
	return (str);
}
