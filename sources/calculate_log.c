/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/17 00:34:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
/*\*/
int	ccl_time(char **date, int itype) {
	int		idate = -1;
	int		og_itype = itype;
	int		index = 0;
	char	stash[3];
	int		res = 0;

	while (date[++idate]) {
		itype = og_itype;
		index = 0;
		while (index < 2)
			stash[index++] = date[idate][itype++];
		stash[index] = 0;
		res += atoi(stash);
	}
	return (res);
}

void	calculate_log(char **date) {
	int		res_min = 0;
	int		res_hour = 0;
	int		res_sec = 0;

	// CALCULATES SECONDS
	res_sec = ccl_time(date, 18);
	res_min = res_sec / 60;
	res_sec %= 60;
	// CALCULATES MINUTES
	res_min += ccl_time(date, 15);
	res_hour = res_min / 60;
	res_min %= 60;
	// CALCULATES HOURS
	res_hour += ccl_time(date, 12);
	printf("\033[1;36m~~~~ Logged time = \033[4m%dh %dmin %ds\033[0m\033[1;36m ~~~~\n\n\033[0m", res_hour, res_min, res_sec);
	if (res_hour < 140)
		printf("--> \033[1m%dh %dmin %ds\033[0m left\n\n", 139 - res_hour, 60 - res_min, 60 - res_sec);
	else {
		res_hour -= 140;
		if (res_hour > 70) {
			res_hour = 70;
			res_min = 0;
			res_sec = 0;
		}
		printf("--> \033[1m%dh %dmin %ds\033[0m additional time for next month\n\n", res_hour, res_min, res_sec);
	}
}
/**/