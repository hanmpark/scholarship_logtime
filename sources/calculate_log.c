/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:10 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/17 21:33:30 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
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

int	*ccl_log(char **date) {
	int	*res;

	res = malloc(3 * sizeof(int));
	if (!res)
		return (NULL);
	res[0] = 0; // seconds
	res[1] = 0; // minutes
	res[2] = 0; // hours
	// CALCULATES SECONDS
	res[0] = ccl_time(date, 18);
	res[1] = res[0] / 60;
	res[0] %= 60;
	// CALCULATES MINUTES
	res[1] += ccl_time(date, 15);
	res[2] = res[1] / 60;
	res[1] %= 60;
	// CALCULATES HOURS
	res[2] += ccl_time(date, 12);
	return (res);
}

int	*ccl_total_time(char **date, int *bnlog) {
	int	*ttlog;

	if (bnlog[2] >= 140 && bnlog[2] < 210) {
		bnlog[2] -= 140;
		printf("\033[1mBonus logtime added from previous month = %dh %dmin %ds\n\n\033[0m", bnlog[2], bnlog[1], bnlog[0]);
	} else if (bnlog[2] >= 210) {
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 70;
		printf("\033[1mBonus logtime added from previous month = %dh %dmin %ds\n\n\033[0m", bnlog[2], bnlog[1], bnlog[0]);
	} else {
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
		printf("\033[1;31m| No bonus logtime |\n\n\033[0m");
	}
	ttlog = ccl_log(date);
	ttlog[0] += bnlog[0];
	if (ttlog[0] > 59) {
		ttlog[1] += ttlog[0] / 60;
		ttlog[0] %= 60;
	}
	ttlog[1] += bnlog[1];
	if (ttlog[1] > 59) {
		ttlog[2] += ttlog[1] / 60;
		ttlog[1] %= 60;
	}
	ttlog[2] += bnlog[2];
	free(bnlog);
	return (ttlog);
}
/**/