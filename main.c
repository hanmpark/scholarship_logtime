/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/16 11:40:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/scholarship_logtime.h"

/*\*/
// FINDS THE 26TH OR LESS DAY
char	*find_day(int month, int fd) {
	char	*str;
	char	*str_month;

	while (1) {
		str = get_next_line(fd);
		str_month = month_is(str);
		if (atoi(str_month) == month || atoi(str_month) == month - 1)
			break ;
		free(str);
	}
	free(str_month);
	return (str);
}

// GET MONTH
char	**parse_month(int month, int fd) {
	char	*str_day;
	char	*str_month;
	char	**str;
	int		index = 0;

	str = calloc(32, sizeof(char *));
	if (!str)
		return (NULL);
	str[index] = find_day(month, fd);
	str_day = day_is(str[index]);
	str_month = month_is(str[index]);
	while (atoi(str_day) > 26) {
		free(str[index]);
		str[index] = get_next_line(fd);
		free(str_day);
		str_day = day_is(str[index]);
	}
	while (atoi(str_month) == month && atoi(str_day) < 27) {
		str[++index] = get_next_line(fd);
		free(str_month);
		free(str_day);
		str_month = month_is(str[index]);
		str_day = day_is(str[index]);
	}
	if (index == 0)
		index--;
	while (atoi(str_month) == month - 1 && atoi(str_day) > 26) {
		str[++index] = get_next_line(fd);
		free(str_month);
		free(str_day);
		str_month = month_is(str[index]);
		str_day = day_is(str[index]);
	}
	if (atoi(str_month) != month - 1 || (atoi(str_month) == month - 1 && atoi(str_day) <= 26)) {
		free(str[--index]);
		str[--index] = 0;
	}
	return (str);
}

int	main(void) {
	int		month;
	int		fd;
	int		i = 0;
	char	**date;

	printf("Month: ");
	scanf("%d", &month);
	if (month < 1 || month > 12) {
		printf("Month doesn't exist...\n");
		return (-1);
	}
	fd = open("text_file.txt", O_RDONLY);
	date = parse_month(month, fd);
	while (date[i]) {
		printf("%s", date[i++]);
		free(date[i]);
	}
	free(date);
	return (0);
}
/**/