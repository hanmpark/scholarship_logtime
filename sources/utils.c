/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/21 17:06:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

void	free_month(char **date)
{
	int	i;

	i = 0;
	while (i < 32)
		free(date[i++]);
	free(date);
}

void	free_holidays(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	trim_tab(char **tab, int len)
{
	char	*firststr;
	int		i;
	int		k;

	i = 0;
	firststr = ft_substr(tab[i], 1, 22);
	free(tab[i]);
	tab[i] = firststr;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] && k < len)
			k++;
		tab[i][k++] = '\n';
		tab[i][k] = 0;
		tab[i][0] = ' ';
		tab[i][11] = ' ';
		tab[i][13] = ' ';
		i++;
	}
	return (i);
}

static int	animated_bar(char *color, int prct, int printprct)
{
	int		i;
	char	*prctstr;

	i = 0;
	ft_printf("[");
	while (i++ < 31)
		ft_printf("-");
	ft_printf("] %s%d%%", color, prct);
	prctstr = ft_itoa(prct);
	i += (int)ft_strlen(prctstr) + 2;
	free(prctstr);
	while (i--)
		ft_printf("\b");
	while (i++ < printprct && i < 31)
	{
		ft_printf("%s▰%s", color, DEF);
		usleep(50000);
	}
	return (i);
}

void	print_progress(int tthours, int hours)
{
	int		i;
	int		prct;
	int		printprct;
	char	*color;

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
		ft_printf("-");
	ft_printf("] %s%d%%%s\n\n", color, prct, DEF);
}
