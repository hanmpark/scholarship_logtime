/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:13:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/21 18:47:16 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scholarship_logtime.h"

static void	print_holidays(char **tab, int year, int i, int fd)
{
	while (tab[i] && ft_atoi(tab[i] + 2) == year)
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

static void	resort_holidays(char **tab, int fd)
{
	int	i;

	i = 0;
	while (tab[i] && (ft_atoi(tab[i] + 2) != current_year()
		|| ft_atoi(tab[i] + 7) != current_month()))
		i++;
	print_holidays(tab, current_year(), i, fd);
	while (tab[i] && (ft_atoi(tab[i] + 2) != current_year() - 1
		|| ft_atoi(tab[i] + 7) != 12))
		i++;
	print_holidays(tab, current_year() - 1, i, fd);
	free_holidays(tab);
}

static void	resort_dates(char **tab, int fd)
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

void	api_public_holidays(void)
{
	int		fd;
	char	*str;
	char	**res;

	fd = open("holidays.txt", O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ',');
	free(str);
	fd = open("holidays.txt", O_WRONLY | O_TRUNC);
	resort_holidays(res, fd);
	close(fd);
}

void	api_dates(void)
{
	int		fd;
	char	*str;
	char	**res;

	fd = open("dates.txt", O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ',');
	free(str);
	fd = open("dates.txt", O_WRONLY | O_TRUNC);
	resort_dates(res, fd);
	close(fd);
}
