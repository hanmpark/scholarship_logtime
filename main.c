/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/17 00:39:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/scholarship_logtime.h"

/*\*/
// FINDS THE 26TH OR LESS DAY
char	*find_day(int month, int lastmonth, int fd) {
	char	*str;
	char	*str_month;
	char	*str_day;
	
	str = get_next_line(fd);
	str_month = month_is(str);
	while (atoi(str_month) != month) {
		if (atoi(str_month) == lastmonth)
			break ;
		free(str);
		str = get_next_line(fd);
		if (!str)
			return(NULL);
		free(str_month);
		str_month = month_is(str);
	}
	str_day = day_is(str);
	while (atoi(str_month) == month && atoi(str_day) > 26) {
		free(str);
		str = get_next_line(fd);
		free(str_day);
		str_day = day_is(str);
	}
	if (atoi(str_month) == lastmonth && atoi(str_day) < 27) {
		free(str_month);
		free(str_day);
		return (NULL);
	}
	free(str_month);
	free(str_day);
	return (str);
}

// GET MONTH
char	**parse_month(int month, int fd) {
	char	*str_day;
	char	*str_month;
	char	**str;
	int		lastmonth = month - 1;
	int		index = 0;

	str = calloc(32, sizeof(char *));
	if (!str)
		return (NULL);
	if (month == 1)
		lastmonth = 12;
	str[index] = find_day(month, lastmonth, fd);
	if (!str[index])
		return (NULL);
	str_day = day_is(str[index]);
	str_month = month_is(str[index]);
	
	while (atoi(str_month) == month && atoi(str_day) < 27) {
		str[++index] = get_next_line(fd);
		free(str_month);
		free(str_day);
		str_month = month_is(str[index]);
		str_day = day_is(str[index]);
	}
	while (atoi(str_month) == lastmonth && atoi(str_day) > 26) {
		str[++index] = get_next_line(fd);
		free(str_month);
		free(str_day);
		str_month = month_is(str[index]);
		str_day = day_is(str[index]);
	}
	if (atoi(str_month) == lastmonth && atoi(str_day) <= 26) {
		free(str[index]);
		str[index] = 0;
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
	return (0);
}
/**/