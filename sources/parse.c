/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:53:20 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/16 15:27:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static void	print_progress(int tthours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	i = 0;
	printf("%s%sProgress log:%s\t|", UL, PURPLE, DEF);
	prct = 100 * tthours / 140;
	printprct = 23 * (int)prct / 100;
	if (prct < 26)
		color = RED;
	else if (prct < 76)
		color = YELLOW;
	else
		color = GREEN;
	while (i++ < printprct && i < 23)
		printf("%s▰%s", color, DEF);
	while (i++ < 23)
		printf("-");
	printf("| ");
	printf("%s%d%%%s\n\n", color, prct, DEF);
}

void	parse_calculation(char **date, char **bonus_date)
{
	int	*stdlog;
	int	*bnlog;
	int	*ttlog;

	stdlog = ccl_log(date);
	if (bonus_date)
		bnlog = ccl_log(bonus_date);
	else
	{
		(void)bonus_date;
		bnlog = malloc(3 * sizeof(char));
		bnlog[0] = 0;
		bnlog[1] = 0;
		bnlog[2] = 0;
		printf("%sCan't calculate for bonus logtime...\n%s", RED, DEF);
	}
	ttlog = ccl_total_time(date, bnlog);
	printf("%s%sTotal logtime = %s%dh %dmin %ds%s\n\n", CYAN, BOLD, UL, ttlog[2], ttlog[1], ttlog[0], DEF);
	int	tthours;
	tthours = ttlog[2];
	check_logtime(stdlog, ttlog);
	print_progress(tthours);
	free(ttlog);
	free(stdlog);
}

char	**parse_month(int month, int fd)
{
	char	**str;
	int		lastmonth;

	str = calloc(32, sizeof(char *));
	if (!str)
		return (NULL);
	if (month == 1)
		lastmonth = 12;
	else
		lastmonth = month - 1;
	str[0] = get_day(month, lastmonth, fd);
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	get_month(str, month, lastmonth, fd);
	return (str);
}
