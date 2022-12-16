/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/16 02:58:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*\*/
char	*check_month(int month, int fd) {
	char	str_month[3];
	char	*str;
	int		j;
	int		i;

	while (1) {
		i = 0;
		j = 5;
		str = get_next_line(fd);
		while (i < 2)
			str_month[i++] = str[j++];
		str_month[i] = 0;
		if (atoi(str_month) == month || atoi(str_month) == month - 1)
			break ;
		free(str);
	}
	return (str);
}

char	**parse_month(int month, int fd) {
	char	str_day[3];
	char	*str[32];
	int		index;
	int		j = 8;
	int		i = 0;

	str[0] = check_month(month, fd);
	while (i < 2)
		str_day[i++] = str[0][j++];
	while (atoi(str_day) > 26) {
		i = 0;
		j = 8;
		free(str[0]);
		str[0] = get_next_line(fd);
		while (i < 2)
			str_day[i++] = str[0][j++];
		str_day[i] = 0;
	}
	printf("%s", str[0]);
	index = 0;
	while (atoi(str_day) < 27 && atoi(str_day) > 0) {
		i = 0;
		j = 8;
		str[++index] = get_next_line(fd);
		printf("%s", str[index]);
		while (i < 2)
			str_day[i++] = str[index][j++];
		str_day[i] = 0;
	}
	str[index] = 0;
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

	int	index = 0;
	//while (date[index]) {
	//	printf("%s", date[index++]);
	//}

	return (0);
}
/**/