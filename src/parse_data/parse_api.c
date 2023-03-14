/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:13:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:21:02 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"
#include "find_time.h"
#include "parse.h"

static void	write_holidays(char **tab, int year, int i, int fd)
{
	while (tab[i] && atoi(tab[i] + 2) == year)
	{
		write(fd, " ", 1);
		tab[i] += 2;
		tab[i][10] = ' ';
		ft_putstr_fd(tab[i], fd);
		write(fd, "\n", 1);
		tab[i] -= 2;
		i--;
	}
}

static void	sort_holidays(char **tab, int fd)
{
	int	i;

	i = 0;
	while (tab[i] && atoi(tab[i] + 2) != current_year())
		i++;
	while (tab[i] && atoi(tab[i] + 7) < current_month())
		i++;
	write_holidays(tab, current_year(), i, fd);
	while (tab[i] && atoi(tab[i] + 2) != current_year() - 1)
		i++;
	while (tab[i] && atoi(tab[i] + 7) != 12)
		i++;
	write_holidays(tab, current_year() - 1, i, fd);
	free_holidays(tab);
}

static void	sort_dates(char **tab, int fd)
{
	int	i;

	trim_tab(tab, 22);
	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

static void	parse_json(const char *txt_file, int dates)
{
	int		fd;
	char	*str;
	char	**res;

	fd = open(txt_file, O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ',');
	free(str);
	fd = open(txt_file, O_WRONLY | O_TRUNC);
	if (dates == HOLIDAYS)
		sort_holidays(res, fd);
	else if (dates == DATES)
		sort_dates(res, fd);
	close(fd);
}

void	parse_api(void)
{
	parse_json("holidays.txt", HOLIDAYS);
	parse_json("dates.txt", DATES);
}
