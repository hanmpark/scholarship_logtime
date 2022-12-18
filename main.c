/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/18 19:19:52 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

/*\*/
int	main(void)
{
	int		month;
	int		fd;
	int		i = 0;
	int		lastmonth;
	char	**date;
	char	**bonus_date;

	printf("Month: ");
	scanf("%d", &month);
	if (month < 1 || month > 12)
	{
		printf("\033[1;31mMonth doesn't exist...\n\033[0m");
		return (-1);
	}
	lastmonth = month - 1;
	if (month == 1)
		lastmonth = 12;
	fd = open("texts/text_file.txt", O_RDONLY);
	date = parse_month(month, fd);
	close(fd);
	if (!date)
	{
		printf("\033[1;31mCan't calculate for this month...\n\033[0m");
		return (-1);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	bonus_date = parse_month(lastmonth, fd);
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