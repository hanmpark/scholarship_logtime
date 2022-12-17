/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/17 21:32:41 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

/*\*/
void	parse_calculation(char **date, char **bonus_date) {
	int	*stdlog;
	int	*bnlog;
	int	*ttlog;
	
	stdlog = ccl_log(date);
	if (bonus_date)
		bnlog = ccl_log(bonus_date);
	else {
		(void)bonus_date;
		bnlog = malloc(3 * sizeof(char));
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
		printf("\033[1;31mCan't calculate for bonus logtime...\n\033[0m");
	}
	ttlog = ccl_total_time(date, bnlog);
	printf("\033[1;36m~~~~ Logged time = \033[4m%dh %dmin %ds\033[0m\033[1;36m ~~~~\n\033[0m", ttlog[2], ttlog[1], ttlog[0]);
	if (ttlog[2] < 140) {
		printf("--> \033[1m%dh %dmin %ds\033[0m left\n\n", 139 - stdlog[2], 60 - stdlog[1], 60 - stdlog[0]);
	} else if (stdlog[2] >= 140 && stdlog[2] < 210) {
		stdlog[2] -= 140;
		printf("--> \033[1mYou are good for this month !\n\n\033[0m");
		printf("--> \033[1m%dh %dmin %ds\033[0m additional time for next month\n\n", stdlog[2], stdlog[1], stdlog[0]);
	} else if (stdlog[2] >= 210) {
		stdlog[2] = 70;
		stdlog[1] = 0;
		stdlog[0] = 0;
		printf("--> \033[1mYou are good for this month !\n\033[0m");
		printf("--> \033[1m%dh %dmin %ds\033[0m additional time for next month\n\n", stdlog[2], stdlog[1], stdlog[0]);
	} else
		printf("--> \033[1mYou are good for this month !\n\n\033[0m");
	free(ttlog);
	free(stdlog);
}

int	main(void) {
	int		month;
	int		fd;
	int		i = 0;
	char	**date;
	char	**bonus_date;

	printf("Month: ");
	scanf("%d", &month);
	if (month < 1 || month > 12) {
		printf("\033[1;31mMonth doesn't exist...\n\033[0m");
		return (-1);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	date = parse_month(month, fd);
	close(fd);
	if (!date) {
		printf("\033[1;31mCan't calculate for this month...\n\033[0m");
		return (-1);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	bonus_date = parse_month(month - 1, fd);
	close(fd);
	printf("\n");
	printf("\033[1;34mTHE CHOSEN MONTH'S LOGTIMES:\n\033[0m");
	while (date[i])
		printf("\t- %s", date[i++]);
	printf("\n");
	parse_calculation(date, bonus_date);
	if (bonus_date)
		free_date(bonus_date);
	free_date(date);
	return (0);
}
/**/