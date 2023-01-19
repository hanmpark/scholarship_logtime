/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/19 14:55:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"
#include <time.h>

/* CLEAR DATE */
void	free_month(char **date)
{
	int	i;

	i = 0;
	while (i < 32)
		free(date[i++]);
	free(date);
}

void	print_progress(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	i = 0;
	printf("|");
	prct = 100 * tthours / hours;
	printprct = 23 * prct / 100;
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

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
