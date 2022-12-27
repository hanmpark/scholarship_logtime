/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/27 16:58:17 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

void	print_result(char **date, char **bonus_date)
{
	int	i;

	i = 0;
	printf("\n");
	printf("\033[1;34mTHE CHOSEN MONTH'S LOGTIMES:\n\033[0m");
	while (date[i])
	{
		printf("  - %s", date[i]);
		i++;
	}
	printf("\n");
	parse_calculation(date, bonus_date);
	if (bonus_date)
		free_date(bonus_date);
	free_date(date);
}

int	main(void)
{
	int		month;
	int		fd;
	int		lastmonth;
	char	**date;
	char	**bonus_date;

	month = current_month();
	if (current_day() >= 27 && current_day() <= 31)
		month++;
	if (!month)
	{
		printf("\033[1;31mThere was a problem looking for the current month...\n\n\033[0m");
		return (0);
	}
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	fd = open("texts/text_file.txt", O_RDONLY);
	date = parse_month(month, fd);
	close(fd);
	if (!date)
	{
		printf("\033[1;31mCan't calculate for this month...\n\n\033[0m");
		return (0);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	bonus_date = parse_month(lastmonth, fd);
	close(fd);
	print_result(date, bonus_date);
	return (0);
}
