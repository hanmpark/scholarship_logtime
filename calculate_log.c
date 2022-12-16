/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/16 17:53:22 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/scholarship_logtime.h"
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
	int		ihours = 12;
	int		iminutes = 15;
	int		iseconds = 18;

	int		res_min = 0;
	int		res_hour = 0;
	int		res_sec = 0;

	// CALCULATES SECONDS
	res_sec = ccl_time(date, iseconds);
	res_min = res_sec / 60;
	res_sec %= 60;
	printf("%d seconds\n", res_sec);

	// CALCULATES MINUTES
	res_min += ccl_time(date, iminutes);
	res_hour = res_min / 60;
	res_min %= 60;
	printf("%d minutes\n", res_min);

	//CALCULATES HOURS
	res_hour += ccl_time(date, ihours);
	printf("%d hours\n", res_hour);
}
/**/