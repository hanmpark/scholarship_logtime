/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/17 12:19:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/scholarship_logtime.h"

/*\*/
int	main(void) {
	int		month;
	int		fd;
	int		i = 0;
	char	**date;

	printf("Month: ");
	scanf("%d", &month);
	if (month < 1 || month > 12) {
		printf("\033[1;31mMonth doesn't exist...\n\033[0m");
		return (-1);
	}
	fd = open("texts/text_file.txt", O_RDONLY);
	date = parse_month(month, fd);
	if (!date) {
		printf("\033[1;31mCan't calculate for this month...\n\033[0m");
		return (-1);
	}
	close(fd);
	printf("\n");
	printf("\033[1;34mTHE CHOSEN MONTH'S LOGTIMES:\n\033[0m");
	while (date[i])
		printf("\t- %s", date[i++]);
	printf("\n");
	calculate_log(date);
	free_date(date);
	return (0);
}
/**/