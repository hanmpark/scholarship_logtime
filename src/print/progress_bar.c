/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:39:00 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:54:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "print.h"

#include <string.h>

static int	animated_bar(char *color, int prct, int printprct)
{
	int		i;
	char	prctstr[10];

	i = 0;
	printf("[");
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%", color, prct);
	snprintf(prctstr, sizeof(prctstr), "%d", prct);
	i += (int)strlen(prctstr) + 2;
	while (i--)
		printf("\b");
	while (i++ < printprct && i < 31)
	{
		printf("%s▰%s", color, DEF);
		usleep(50000);
	}
	return (i);
}

// Simple progression bar
void	print_progressbar(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

	printf("%s%sProgress log:%s\t", UL, PURPLE, DEF);
	i = 0;
	prct = 100 * tthours / hours;
	printprct = 31 * prct / 100;
	if (prct < 26)
		color = RED;
	else if (prct < 76)
		color = YELLOW;
	else
		color = GREEN;
	i = animated_bar(color, prct, printprct);
	while (i++ < 31)
		printf("-");
	printf("] %s%d%%%s\n\n", color, prct, DEF);
}
